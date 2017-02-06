--- Usuwanie procedur, funkcji i wyzwalaczy:
IF OBJECT_ID('dodajUcznia') IS NOT NULL 
drop procedure dodajUcznia

IF OBJECT_ID('dodajNauczyciela') IS NOT NULL 
drop procedure dodajNauczyciela

IF OBJECT_ID('dodajPrzedmiot') IS NOT NULL 
drop procedure dodajPrzedmiot

IF OBJECT_ID('zapiszKlaseNaLekcje') IS NOT NULL 
drop procedure zapiszKlaseNaLekcje

IF OBJECT_ID('przydzielPrzedmiotProfilowi') IS NOT NULL 
drop procedure przydzielPrzedmiotProfilowi

IF OBJECT_ID('przydzielPrzedmiotNauczycielowi') IS NOT NULL 
drop procedure przydzielPrzedmiotNauczycielowi

IF OBJECT_ID('przydzielWychowawce') IS NOT NULL 
drop procedure przydzielWychowawce

IF OBJECT_ID('kimJestem') IS NOT NULL 
drop function kimJestem

IF OBJECT_ID('wstawOcene') IS NOT NULL 
drop procedure wstawOcene

IF OBJECT_ID('sredniaWazonaOcen') IS NOT NULL 
drop function sredniaWazonaOcen

IF OBJECT_ID('propozycjaOceny') IS NOT NULL 
drop function propozycjaOceny

IF OBJECT_ID('wystawOceneKoncowa') IS NOT NULL 
drop procedure wystawOceneKoncowa

IF OBJECT_ID('zmienAdresUcznia') IS NOT NULL 
drop procedure zmienAdresUcznia

IF OBJECT_ID('zmienAdresNauczyciela') IS NOT NULL 
drop procedure zmienAdresNauczyciela

IF OBJECT_ID('usunUcznia') IS NOT NULL 
drop procedure usunUcznia

IF OBJECT_ID('t_usunUczniaOcena') IS NOT NULL 
drop trigger t_usunUczniaOcena

IF OBJECT_ID('t_usunUcznia') IS NOT NULL 
drop trigger t_usunUcznia

IF OBJECT_ID('usunNauczyciela') IS NOT NULL 
drop procedure usunNauczyciela

IF OBJECT_ID('t_usunNauczyciela') IS NOT NULL 
drop trigger t_usunNauczyciela

IF OBJECT_ID('t_NauczycielPrzedmiot') IS NOT NULL 
drop trigger t_NauczycielPrzedmiot

IF OBJECT_ID('t_usunNauczycielaKlasa') IS NOT NULL 
drop trigger t_usunNauczycielaKlasa

IF OBJECT_ID('t_usunZLekcja') IS NOT NULL 
drop trigger t_usunZLekcja

IF OBJECT_ID('usunPrzedmiot') IS NOT NULL 
drop procedure usunPrzedmiot

IF OBJECT_ID('t_usunPrzedmiot') IS NOT NULL 
drop trigger t_usunPrzedmiot

IF OBJECT_ID('t_usunPrzedmiotProfil') IS NOT NULL 
drop trigger t_usunPrzedmiotProfil
----------------
go
--- Dodawanie ucznia:
create procedure dodajUcznia
	@Imiê varchar(20),
	@Nazwisko varchar(30),
	@Klasa int,
	@PESEL varchar(11),
	@Ulica varchar(50),
	@nrDomu int,
	@nrMieszkania int,
	@imiêOjca varchar(20),
	@imiêMatki varchar(20)
as
begin
	if exists (select * from Uczeñ where PESEL = @PESEL)
		print 'Uczeñ ju¿ jest w bazie.'
	else
	begin
		declare @idUcznia int
		declare @Aktywny bit
		set @idUcznia = (select max(idUcznia)+1 from Uczeñ)
		set @Aktywny = 1
		insert into Uczeñ
		values (@idUcznia, @Imiê, @Nazwisko, @Klasa, @PESEL, @Ulica, @nrDomu, @nrMieszkania, @imiêOjca, @imiêMatki, @Aktywny)
	end
end
----------------
go
--- Dodanie nauczyciela:
create procedure dodajNauczyciela
	@Imiê varchar(20),
	@Nazwisko varchar(30),
	@Ulica varchar(50),
	@nrDomu int,
	@nrMieszkania int
as
begin
	if exists (select * from Nauczyciel where ((Imiê = @Imiê) and (Nazwisko = @Nazwisko) and (Ulica = @Ulica) and (nrDomu = @nrDomu) and (nrMieszkania = @nrMieszkania)))
		print 'Nauczyciel jest ju¿ w bazie.'
	else
	begin
		declare @idNauczyciela int
		set @idNauczyciela = (select max(idNauczyciela)+1 from Nauczyciel)
		declare @Aktywny bit
		set @Aktywny = 1
		declare @DodatkowaFunkcja varchar(15)
		set @DodatkowaFunkcja = 'brak'
		insert into Nauczyciel values
		(@idNauczyciela, @Imiê, @Nazwisko, @Ulica, @nrDomu, @nrMieszkania, @DodatkowaFunkcja, @Aktywny)
	end
end
----------------
go
--- Dodawanie przedmiotu:
create procedure dodajPrzedmiot
	@Nazwa varchar(30),
	@Poziom varchar(30),
	@iloœæGodzin int
as
begin
	if exists (select * from Przedmiot where ((Nazwa = @Nazwa) and (Poziom = @Poziom) and (iloœæGodzin = @iloœæGodzin)))
		print 'Przedmiot jest ju¿ w bazie.'
	else
	begin
		declare @idPrzedmiotu int
		set @idPrzedmiotu = (select max(idPrzedmiotu)+1 from Przedmiot)
		declare @Aktywny bit
		set @Aktywny = 1
		insert into Przedmiot values
		(@idPrzedmiotu, @Nazwa, @Poziom, @iloœæGodzin, @Aktywny)
	end
end
----------------
go
--- Zapisywanie klasy na lekcjê:
create procedure zapiszKlaseNaLekcje
	@Dzieñ varchar(20),
	@Godzina time(0),
	@Klasa int,
	@Przedmiot int,
	@Nauczyciel int
as
begin
	if exists (select * from Lekcja where ((Dzieñ = @Dzieñ) and (Godzina = @Godzina) and (Przedmiot = @Przedmiot) and (Nauczyciel = @Nauczyciel)))
		print 'Ta lekcja jest ju¿ zajêta.'
	else if exists (select * from Lekcja where ((Dzieñ = @Dzieñ) and (Godzina = @Godzina) and (Klasa = @Klasa)))
		print 'Klasa jest ju¿ zapisana na inn¹ lekcjê.'
	else
	begin
		declare @idLekcji int
		set @idLekcji = (select max(idLekcji)+1 from Lekcja)
		insert into Lekcja values
		(@idLekcji, @Dzieñ, @Godzina, @Klasa, @Przedmiot, @Nauczyciel)
	end
end
----------------
go
--- Przydzia³ przedmiotu do profilu:
create procedure przydzielPrzedmiotProfilowi
	@idPrzedmiotu int,
	@idProfilu int
as
begin
	if exists (select * from PrzedmiotProfil where ((Profil = @idProfilu) and (Przedmiot = @idPrzedmiotu)))
	begin
		insert into PrzedmiotProfil values
		(@idPrzedmiotu, @idProfilu)
	end
	else
		print 'Przedmiot lub profil nie istnieje w bazie.'
end
----------------
go
--- Przydzielanie nauczycielowi przedmiotu:
create procedure przydzielPrzedmiotNauczycielowi
	@idNauczyciela int,
	@idPrzedmiotu int
as
begin
	if exists (select * from NauczycielPrzedmiot where ((Nauczyciel = @idNauczyciela) and (Przedmiot = @idPrzedmiotu)))
	begin
		declare @idPary int
		set @idPary = (select max(idPary)+1 from NauczycielPrzedmiot)
		insert into NauczycielPrzedmiot values
		(@idPary, @idNauczyciela, @idPrzedmiotu)
		end
	else
		print 'Nauczyciel lub przedmiot nie istnieje w bazie.'
end
----------------
go
--- Przydzielanie wychowawcy do klasy:
create procedure przydzielWychowawce
	@idKlasy int,
	@idNauczyciela int
as
begin
	if (exists (select * from Klasa where idKlasy = @idKlasy)) and (exists (select * from Nauczyciel where idNauczyciela = @idNauczyciela))
	begin
		update Klasa
		set Wychowawca = @idNauczyciela
		where idKlasy = @idKlasy
	end
	else
		print 'Klasa lub nauczyciel nie istnieje.'
end
----------------
go
--- Kto wstawia ocenê:
create function kimJestem(@idNauczyciela int, @idPrzedmiotu int) returns int
as
begin
	return (select idPary from NauczycielPrzedmiot where ((Nauczyciel = @idNauczyciela) and (Przedmiot = @idPrzedmiotu)))
end
----------------
go
--- Wstawianie oceny cz¹stkowej:
create procedure wstawOcene
	@Nauczyciel int,
	@Przedmiot int,
	@Uczeñ int,
	@Wartoœæ float,
	@Waga int,
	@Kategoria varchar(100)
as
begin
	declare @NauczycielPrzedmiot int
	set @NauczycielPrzedmiot = dbo.kimJestem(@Nauczyciel, @Przedmiot)
	if exists (select * from Ocena o where ((o.NauczycielPrzedmiot = @NauczycielPrzedmiot) and (o.Uczeñ = @Uczeñ)))
	begin
		declare @idOceny int
		declare @Koncowa bit
		set @idOceny = (select max(idOceny)+1 from Ocena)
		set @Koncowa = 0
		insert into Ocena values
		(@idOceny, @NauczycielPrzedmiot, @Uczeñ, @Wartoœæ, @Waga, @Kategoria, @Koncowa)
	end
	else
		print 'Uczeñ, nauczyciel lub przedmiot nie istnieje w bazie ocen.'
end
----------------
go
--- Obliczanie œredniej wa¿onej ocen:
create function sredniaWazonaOcen(@idUcznia int, @NauczycielPrzedmiot int) returns float
as
begin
	declare @wynik float
	set @wynik = 0
	if exists (select * from Ocena o where ((o.NauczycielPrzedmiot = @NauczycielPrzedmiot) and (o.Uczeñ = @idUcznia)))
	begin
		set @wynik = (select (sum(Wartoœæ*Waga)/sum(Waga))
						from Ocena
						where (Uczeñ = @idUcznia and NauczycielPrzedmiot = @NauczycielPrzedmiot))
	end
	return @wynik
end
----------------
go
--- Propozycja oceny koñcowej na podstawie œredniej:
create function propozycjaOceny(@srednia float) returns float
as
begin
	if (@srednia >= 5.75)
		return 6
	else if (@srednia >= 5.25)
		return 5.5
	else if (@srednia >= 4.75)
		return 5
	else if (@srednia >= 4.25)
		return 4.5
	else if (@srednia >= 3.75)
		return 4
	else if (@srednia >= 3.25)
		return 3.5
	else if (@srednia >= 2.75)
		return 3
	else if (@srednia >= 2.25)
		return 2.5
	else if (@srednia >= 1.75)
		return 2
	return 1
end
----------------
go
--- Wystawianie oceny koñcowej:
create procedure wystawOceneKoncowa
	@Nauczyciel int,
	@Przedmiot int,
	@Uczeñ int
as
begin
	declare @NauczycielPrzedmiot int
	set @NauczycielPrzedmiot = dbo.kimJestem(@Nauczyciel, @Przedmiot)
	if exists (select * from Ocena o where ((o.NauczycielPrzedmiot = @NauczycielPrzedmiot) and (o.Uczeñ = @Uczeñ)))
	begin
		declare @idOceny int
		declare @Waga int
		declare @Kategoria varchar(100)
		declare @Koncowa bit
		declare @Wartoœæ float
		set @idOceny = (select max(idOceny)+1 from Ocena)
		set @Waga = 0
		set @Kategoria = 'KOÑCOWA'
		set @Koncowa = 1
		set @Wartoœæ = dbo.propozycjaOceny(dbo.sredniaWazonaOcen(@Uczeñ, @NauczycielPrzedmiot))
		if exists (select * from Ocena where ((NauczycielPrzedmiot = @NauczycielPrzedmiot) and (Uczeñ = @Uczeñ) and (Wartoœæ = @Wartoœæ) and (Waga = @Waga) and (Kategoria = @Kategoria) and (Koñcowa = @Koncowa)))
			print 'Ocena koñcowa zosta³a ju¿ wystawiona.'
		else
		begin
			insert into Ocena values
			(@idOceny, @NauczycielPrzedmiot, @Uczeñ, @Wartoœæ, @Waga, @Kategoria, @Koncowa)
		end
	end
	else
		print 'Uczeñ, nauczyciel lub przedmiot nie istnieje w bazie ocen.'
end
----------------
go
--- Modyfikacja adresu zamieszkania ucznia:
create procedure zmienAdresUcznia
	@idUcznia int,
	@Ulica varchar(50),
	@nrDomu int,
	@nrMieszkania int
as
begin
	if exists (select * from Uczeñ where idUcznia = @idUcznia)
	begin
		update Uczeñ
		set Ulica = @Ulica,
		nrDomu = @nrDomu,
		nrMieszkania = @nrMieszkania
		where idUcznia = @idUcznia
	end
	else
		print 'Ucznia nie ma w bazie.'
end
----------------
go
--- Modyfikacja adresu zamieszkania nauczyciela:
create procedure zmienAdresNauczyciela
	@idNauczyciela int,
	@Ulica varchar(50),
	@nrDomu int,
	@nrMieszkania int
as
begin
	if exists (select * from Nauczyciel where idNauczyciela = @idNauczyciela)
	begin
		update Nauczyciel
		set Ulica = @Ulica,
		nrDomu = @nrDomu,
		nrMieszkania = @nrMieszkania
		where idNauczyciela = @idNauczyciela
	end
	else
		print 'Nauczyciela nie ma w bazie.'
end
----------------
go
--- Usuwanie ucznia:
create procedure usunUcznia
	@id int
as
begin
	if exists (select * from Uczeñ where idUcznia = @id)
	begin
		delete from Ocena where Uczeñ = @id
		delete from Uczeñ where idUcznia = @id
	end
	else
		print 'Ucznia nie ma w bazie.'
end
----------------
go
--- Wyzwalacz przy usuwaniu z tabeli Ocena:
create trigger t_usunUczniaOcena
on Ocena
instead of delete
as
begin
	print 'Nie mo¿na usun¹æ ucznia bezpoœrednio z bazy! Otrzyma status ucznia nieaktywnego a po trzech miesi¹cach bêdzie usuniêty przez administratora.'
end
----------------
go
--- Wyzwalacz przy usuwaniu z tabeli Uczeñ:
create trigger t_usunUcznia
on Uczeñ
instead of delete
as
begin
	update Uczeñ
	set Aktywny = 0
	from deleted
	where Uczeñ.idUcznia=deleted.idUcznia
end
----------------
go
--- Usuwanie nauczyciela:
create procedure usunNauczyciela
	@id int
as
begin
	if exists (select * from Nauczyciel where idNauczyciela = @id)
	begin
		delete from NauczycielPrzedmiot where Nauczyciel = @id
		delete from Klasa where Wychowawca = @id
		delete from Lekcja where Nauczyciel = @id
		delete from Nauczyciel where idNauczyciela = @id
	end
	else
		print 'Nauczyciela nie ma w bazie.'
end
----------------
go
--- Wyzwalacz przy usuwaniu z tabeli Nauczyciel:
create trigger t_usunNauczyciela
on Nauczyciel
instead of delete
as
begin
	update Nauczyciel
	set Aktywny = 0
	from deleted
	where Nauczyciel.idNauczyciela=deleted.idNauczyciela
end
----------------
go
--- Wyzwalacz przy usuwaniu z tabeli NauczycielPrzedmiot:
create trigger t_NauczycielPrzedmiot
on NauczycielPrzedmiot
instead of delete
as
begin
	print 'Usuniêcia z bazy dokona administrator. Na razie ustawiono status aktywnoœci na 0.'
end
----------------
go
--- Wyzwalacz przy usuwaniu z tabeli Klasa:
create trigger t_usunNauczycielaKlasa
on Klasa
instead of delete
as
begin
	update Klasa
	set Wychowawca = NULL
	from deleted d
	where Klasa.Wychowawca = d.Wychowawca
end
----------------
go
--- Wyzwalacz przy usuwaniu z tabeli Lekcja:
create trigger t_usunZLekcja
on Lekcja
instead of delete
as
begin
	print ''
end
----------------
go
--- Usuwanie przedmiotu:
create procedure usunPrzedmiot
	@id int
as
begin
	if exists (select * from Przedmiot where idPrzedmiotu = @id)
	begin
		delete from NauczycielPrzedmiot where Przedmiot = @id
		delete from PrzedmiotProfil where Przedmiot = @id
		delete from Lekcja where Przedmiot = @id
		delete from Przedmiot where idPrzedmiotu = @id
	end
	else
		print 'Przedmiotu nie ma w bazie.'
end
----------------
go
--- Wyzwalacz przy usuwaniu z tabeli Przedmiot:
create trigger t_usunPrzedmiot
on Przedmiot
instead of delete
as
begin
	update Przedmiot
	set Aktywny = 0
	from deleted
	where Przedmiot.idPrzedmiotu=deleted.idPrzedmiotu
end
----------------
go
--- Wyzwalacz przy usuwaniu z tabeli NauczycielPrzedmiot:
------ jest wy¿ej :)
----------------
go
--- Wyzwalacz przy usuwaniu z tabeli ProfilPrzedmiot:
create trigger t_usunPrzedmiotProfil
on PrzedmiotProfil
instead of delete
as
begin
	print ''
end
----------------
go
--- Wyzwalacz przy usuwaniu z tabeli Lekcja:
----- jest wy¿ej :)
----------------
go