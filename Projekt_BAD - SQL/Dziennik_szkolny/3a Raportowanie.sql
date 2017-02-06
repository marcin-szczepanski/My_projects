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
create view NauczycieleZPrzedmiotami(Nazwisko, Imiê, Przedmiot)
as
	select distinct top(100) percent n.Nazwisko, n.Imiê, p.Nazwa
	from Nauczyciel n inner join NauczycielPrzedmiot np
	on n.idNauczyciela=np.Nauczyciel
	inner join Przedmiot p
	on np.Przedmiot=p.idPrzedmiotu
	order by n.Nazwisko
----------------
go
--- Lista uczniów w szkole:
create view UczniowieWSzkole(Rok, Klasa, Nazwisko, Imiê)
as
	select distinct top(100) percent k.Rok, k.Nazwa, u.Nazwisko, u.Imiê
	from Klasa k inner join Uczeñ u
	on k.idKlasy = u.Klasa
	order by k.Rok
----------------
go
--- Lista klas z profilami i wychowawcami:
create view Klasy(Rok, Klasa, Profil, Wychowawca)
as
	select distinct top(100) percent k.Rok, k.Nazwa, p.Nazwa, n.Nazwisko + ' ' + n.Imiê
	from Profil p inner join Klasa k
	on p.idProfilu = k.Profil
	inner join Nauczyciel n
	on k.Wychowawca = n.idNauczyciela
	order by k.Rok
----------------
go
--- Plan zajêæ:
create view PlanZajec(Dzieñ, Godzina, Rok, Klasa, Przedmiot, Poziom, Nauczyciel)
as
	select top(100) percent l.Dzieñ, l.Godzina, k.Rok, k.Nazwa, p.Nazwa, p.Poziom, n.Nazwisko + ' ' + n.Imiê
	from Klasa k inner join Lekcja l
	on k.idKlasy = l.Klasa
	inner join Przedmiot p
	on l.Przedmiot = p.idPrzedmiotu
	inner join Nauczyciel n
	on l.Nauczyciel = n.idNauczyciela
	order by case when l.Dzieñ = 'pon' then '1'
		when l.Dzieñ = 'wt' then '2'
		when l.Dzieñ = 'œr' then '3'
		when l.Dzieñ = 'czw' then '4'
		when l.Dzieñ = 'pt' then '5'
		else l.Dzieñ end asc
----------------
go
--- Osoby do usuniêcia ze szko³y:
create function doUsuniecia (@ile int)
	returns table
as
	return select distinct top(100) percent u.idUcznia, u.Nazwisko, u.Imiê, k.Rok, k.Nazwa as 'Nazwa klasy'
	from Uczeñ u inner join Klasa k
	on u.Klasa = k.idKlasy
	where u.idUcznia in 
	(
		select Uczeñ from Ocena where
		((Wartoœæ = 1) and (Koñcowa = 1))
		group by Uczeñ
		having (count(*) >= @ile)
	)
----------------
go
--- Najlepszy uczeñ w szkole:
create view najlepszy(idUcznia, Nazwisko, Imiê, Rok, Klasa, ŒredniaOcenKoñcowych)
as
	select distinct u.idUcznia, u.Nazwisko, u.Imiê, k.Rok, k.Nazwa, avg(o.Wartoœæ)
	from Uczeñ u inner join Klasa k
	on u.Klasa = k.idKlasy
	inner join Ocena o
	on u.idUcznia = o.Uczeñ
	where (Koñcowa = 1) and (u.idUcznia in
	(
		select top 1 Uczeñ from Ocena where
		(Koñcowa = 1)
		group by Uczeñ
		order by avg(Wartoœæ) desc
	))
	group by u.idUcznia, u.Nazwisko, u.Imiê, k.Rok, k.Nazwa
----------------
go
--- Najgorszy uczeñ w szkole:
create view najgorszy(idUcznia, Nazwisko, Imiê, Rok, Klasa, ŒredniaOcenKoñcowych)
as
	select distinct u.idUcznia, u.Nazwisko, u.Imiê, k.Rok, k.Nazwa, avg(o.Wartoœæ)
	from Uczeñ u inner join Klasa k
	on u.Klasa = k.idKlasy
	inner join Ocena o
	on u.idUcznia = o.Uczeñ
	where (Koñcowa = 1) and (u.idUcznia in
	(
		select top 1 Uczeñ from Ocena where
		(Koñcowa = 1)
		group by Uczeñ
		order by avg(Wartoœæ) asc
	))
	group by u.idUcznia, u.Nazwisko, u.Imiê, k.Rok, k.Nazwa
----------------
go