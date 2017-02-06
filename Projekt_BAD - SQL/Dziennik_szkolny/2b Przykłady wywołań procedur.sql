exec dodajUcznia 'Maria', 'Bednarska', 3, '97022415371', 'Gdañska', 3, 1, 'Jan', 'Ewa' --- przy drugim i kolejnym wywo³aniu nie dodamy tego samego ucznia
exec dodajNauczyciela 'Jan', 'Wójcik', 'G³ogowska', 55, 3  --- przy drugim i kolejnym wywo³aniu nie dodamy tego samego nauczyciela
exec dodajPrzedmiot 'Historia', 'podstawowy', 2 --- przy drugim i kolejnym wywo³aniu nie dodamy tego samego przedmiotu
exec przydzielPrzedmiotProfilowi 5, 1
exec przydzielPrzedmiotNauczycielowi 5, 3
exec przydzielWychowawce 1, 5
select dbo.kimJestem(3,1) as 'Identyfikator nauczyciela danego przedmiotu'
exec wstawOcene 1, 4, 1, 4.5, 1, 'zadanie przy tablicy'
select dbo.sredniaWazonaOcen(1,2) as 'Œrednia wa¿ona'
select dbo.propozycjaOceny(4.29) as 'Propozycja oceny'
exec wystawOceneKoncowa 1, 4, 1 --- przy drugim i kolejnym wywo³aniu nie dodamy tej samej oceny
exec wystawOceneKoncowa 2, 1 ,1
exec wystawOceneKoncowa 1, 4 ,2
exec wystawOceneKoncowa 4, 5, 3
exec wystawOceneKoncowa 2, 1, 3
exec wystawOceneKoncowa 1, 3, 3
exec zmienAdresUcznia 1, 'Zmieniony adres', 50, 30
exec zmienAdresNauczyciela 1, 'Zmieniony adres', 50, 30
exec usunUcznia 3
exec usunNauczyciela 3
exec usunPrzedmiot 4
---- Gdy podamy nieprawid³owe dane:
exec przydzielPrzedmiotProfilowi 55, 1
exec przydzielPrzedmiotNauczycielowi 55, 3
exec przydzielWychowawce 8, 5
select dbo.kimJestem(8,1) as 'Identyfikator nauczyciela danego przedmiotu'
exec wstawOcene 8, 4, 1, 4.5, 1, 'zadanie przy tablicy'
select dbo.sredniaWazonaOcen(8,2) as 'Œrednia wa¿ona'
exec wystawOceneKoncowa 8, 8, 9
exec wystawOceneKoncowa 2, 1, 2
exec zmienAdresUcznia 10, 'Zmieniony adres', 50, 30
exec zmienAdresNauczyciela 10, 'Zmieniony adres', 50, 30
exec usunUcznia 33
exec usunNauczyciela 33
exec usunPrzedmiot 44