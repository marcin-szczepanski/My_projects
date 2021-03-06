--- Usuwanie ---
IF OBJECT_ID('NauczycieleZPrzedmiotami') IS NOT NULL 
drop view NauczycieleZPrzedmiotami

IF OBJECT_ID('UczniowieWSzkole') IS NOT NULL 
drop view UczniowieWSzkole

IF OBJECT_ID('Klasy') IS NOT NULL 
drop view Klasy

IF OBJECT_ID('PlanZajec') IS NOT NULL 
drop view PlanZajec

IF OBJECT_ID('doUsuniecia') IS NOT NULL 
drop function doUsuniecia

IF OBJECT_ID('najlepszy') IS NOT NULL 
drop view najlepszy

IF OBJECT_ID('najgorszy') IS NOT NULL 
drop view najgorszy
----------------
go
-- Lista nauczycieli z przedmiotami:
create view NauczycieleZPrzedmiotami(Nazwisko, Imi�, Przedmiot)
as
	select distinct top(100) percent n.Nazwisko, n.Imi�, p.Nazwa
	from Nauczyciel n inner join NauczycielPrzedmiot np
	on n.idNauczyciela=np.Nauczyciel
	inner join Przedmiot p
	on np.Przedmiot=p.idPrzedmiotu
	order by n.Nazwisko
----------------
go
--- Lista uczni�w w szkole:
create view UczniowieWSzkole(Rok, Klasa, Nazwisko, Imi�)
as
	select distinct top(100) percent k.Rok, k.Nazwa, u.Nazwisko, u.Imi�
	from Klasa k inner join Ucze� u
	on k.idKlasy = u.Klasa
	order by k.Rok
----------------
go
--- Lista klas z profilami i wychowawcami:
create view Klasy(Rok, Klasa, Profil, Wychowawca)
as
	select distinct top(100) percent k.Rok, k.Nazwa, p.Nazwa, n.Nazwisko + ' ' + n.Imi�
	from Profil p inner join Klasa k
	on p.idProfilu = k.Profil
	inner join Nauczyciel n
	on k.Wychowawca = n.idNauczyciela
	order by k.Rok
----------------
go
--- Plan zaj��:
create view PlanZajec(Dzie�, Godzina, Rok, Klasa, Przedmiot, Poziom, Nauczyciel)
as
	select top(100) percent l.Dzie�, l.Godzina, k.Rok, k.Nazwa, p.Nazwa, p.Poziom, n.Nazwisko + ' ' + n.Imi�
	from Klasa k inner join Lekcja l
	on k.idKlasy = l.Klasa
	inner join Przedmiot p
	on l.Przedmiot = p.idPrzedmiotu
	inner join Nauczyciel n
	on l.Nauczyciel = n.idNauczyciela
	order by case when l.Dzie� = 'pon' then '1'
		when l.Dzie� = 'wt' then '2'
		when l.Dzie� = '�r' then '3'
		when l.Dzie� = 'czw' then '4'
		when l.Dzie� = 'pt' then '5'
		else l.Dzie� end asc
----------------
go
--- Osoby do usuni�cia ze szko�y:
create function doUsuniecia (@ile int)
	returns table
as
	return select distinct top(100) percent u.idUcznia, u.Nazwisko, u.Imi�, k.Rok, k.Nazwa as 'Nazwa klasy'
	from Ucze� u inner join Klasa k
	on u.Klasa = k.idKlasy
	where u.idUcznia in 
	(
		select Ucze� from Ocena where
		((Warto�� = 1) and (Ko�cowa = 1))
		group by Ucze�
		having (count(*) >= @ile)
	)
----------------
go
--- Najlepszy ucze� w szkole:
create view najlepszy(idUcznia, Nazwisko, Imi�, Rok, Klasa, �redniaOcenKo�cowych)
as
	select distinct u.idUcznia, u.Nazwisko, u.Imi�, k.Rok, k.Nazwa, avg(o.Warto��)
	from Ucze� u inner join Klasa k
	on u.Klasa = k.idKlasy
	inner join Ocena o
	on u.idUcznia = o.Ucze�
	where (Ko�cowa = 1) and (u.idUcznia in
	(
		select top 1 Ucze� from Ocena where
		(Ko�cowa = 1)
		group by Ucze�
		order by avg(Warto��) desc
	))
	group by u.idUcznia, u.Nazwisko, u.Imi�, k.Rok, k.Nazwa
----------------
go
--- Najgorszy ucze� w szkole:
create view najgorszy(idUcznia, Nazwisko, Imi�, Rok, Klasa, �redniaOcenKo�cowych)
as
	select distinct u.idUcznia, u.Nazwisko, u.Imi�, k.Rok, k.Nazwa, avg(o.Warto��)
	from Ucze� u inner join Klasa k
	on u.Klasa = k.idKlasy
	inner join Ocena o
	on u.idUcznia = o.Ucze�
	where (Ko�cowa = 1) and (u.idUcznia in
	(
		select top 1 Ucze� from Ocena where
		(Ko�cowa = 1)
		group by Ucze�
		order by avg(Warto��) asc
	))
	group by u.idUcznia, u.Nazwisko, u.Imi�, k.Rok, k.Nazwa
----------------
go