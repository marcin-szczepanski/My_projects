exec dodajUcznia 'Maria', 'Bednarska', 3, '97022415371', 'Gdañska', 4, 1, 'Jan', 'Ewa' --- przy drugim i kolejnym wywo³aniu nie dodamy tego samego ucznia
exec dodajNauczyciela 'Jan', 'Wójcik', 'G³ogowska', 55, 3  --- przy drugim i kolejnym wywo³aniu nie dodamy tego samego nauczyciela
exec dodajPrzedmiot 'Historia', 'podstawowy', 2 --- przy drugim i kolejnym wywo³aniu nie dodamy tego samego przedmiotu
exec zapiszKlaseNaLekcje 'pt', '11:45', 4, 4, 1 --- przy drugim i kolejnym wywo³aniu nie dodamy tej samej lekcji
exec przydzielPrzedmiotProfilowi 5, 1 --- przy drugim i kolejnym wywo³aniu nie przypiszemy tego samego przedmiotu do tego samego profilu
exec przydzielPrzedmiotNauczycielowi 5, 3 --- przy drugim i kolejnym wywo³aniu nie przypiszemy tego samego przedmiotu do tego samego nauczyciela
exec przydzielWychowawce 1, 5 --- mo¿na wywo³ywaæ wielokrotnie, gdy¿ klasa jest aktualizowana a nie dodawana od nowa do bazy
select dbo.kimJestem(3,1) as 'Identyfikator nauczyciela danego przedmiotu'
exec wstawOcene 1, 4, 1, 4.5, 1, 'zadanie przy tablicy'
select dbo.sredniaWazonaOcen(1,2) as 'Œrednia wa¿ona'
select dbo.propozycjaOceny(3.29) as 'Propozycja oceny'
exec wystawOceneKoncowa 1, 4, 1 --- przy drugim i kolejnym wywo³aniu nie dodamy tej samej oceny koñcowej
exec wystawOceneKoncowa 2, 1 ,1
exec wystawOceneKoncowa 1, 4 ,2
exec wystawOceneKoncowa 4, 5, 3
exec wystawOceneKoncowa 2, 1, 3
exec wystawOceneKoncowa 1, 3, 3
exec zmienAdresUcznia 1, 'Zmieniony adres', 50, 30
exec zmienAdresNauczyciela 1, 'Zmieniony adres', 50, 30
exec usunUcznia 3
exec usunNauczyciela 1
exec usunPrzedmiot 4
---- Gdy podamy nieprawid³owe dane:
exec zapiszKlaseNaLekcje 'pt', '11:45', 4, 1, 4 --- gdy klasa jest zapisana na inn¹ lekcjê w tym samym czasie
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