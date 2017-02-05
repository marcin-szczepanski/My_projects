--- Usuwanie ---
IF OBJECT_ID('NauczycieleZPrzedmiotami') IS NOT NULL 
drop view NauczycieleZPrzedmiotami

IF OBJECT_ID('UczniowieWSzkole') IS NOT NULL 
drop view UczniowieWSzkole

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
--- Lista uczniów w szkole
create view UczniowieWSzkole(Rok, Klasa, Nazwisko, Imiê)
as
	select distinct top(100) percent k.Rok, k.Nazwa, u.Nazwisko, u.Imiê
	from Klasa k inner join Uczeñ u
	on k.idKlasy = u.Klasa
	order by k.Rok
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