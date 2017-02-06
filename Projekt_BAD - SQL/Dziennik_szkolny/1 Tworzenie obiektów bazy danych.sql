SET LANGUAGE polski
GO

-- Usuwanie tabel

IF OBJECT_ID('Ocena', 'U') IS NOT NULL 
drop table Ocena

IF OBJECT_ID('PrzedmiotProfil', 'U') IS NOT NULL 
drop table PrzedmiotProfil

IF OBJECT_ID('Uczeñ', 'U') IS NOT NULL 
drop table Uczeñ

IF OBJECT_ID('Lekcja', 'U') IS NOT NULL 
drop table Lekcja

IF OBJECT_ID('Klasa', 'U') IS NOT NULL 
drop table Klasa

IF OBJECT_ID('NauczycielPrzedmiot', 'U') IS NOT NULL 
drop table NauczycielPrzedmiot

IF OBJECT_ID('Nauczyciel', 'U') IS NOT NULL 
drop table Nauczyciel

IF OBJECT_ID('Przedmiot', 'U') IS NOT NULL 
drop table Przedmiot

IF OBJECT_ID('Profil', 'U') IS NOT NULL 
drop table Profil

-- tworzenie tabel

create table Nauczyciel
(idNauczyciela int not null primary key,
Imiê varchar(20) CONSTRAINT ck_imieNauczyciel CHECK (Imiê like '[A-Z]%'),
Nazwisko varchar(30) CONSTRAINT ck_nazwiskoNauczyciel CHECK (Nazwisko like '[A-Z]%'),
Ulica varchar(50),
nrDomu int,
nrMieszkania int,
DodatkowaFunkcja varchar(15) CONSTRAINT ck_dodatkowaFunkcjaNauczyciel CHECK (DodatkowaFunkcja in ('dyrektor', 'wicedyrektor','brak')),
Aktywny bit
);

create table Przedmiot
(idPrzedmiotu int not null primary key,
Nazwa varchar(30),
Poziom varchar(30) CONSTRAINT ck_poziomPrzedmiot CHECK (Poziom in ('podstawowy', 'rozszerzony')),
iloœæGodzin int,
Aktywny bit,
);

create table NauczycielPrzedmiot
(idPary int not null primary key,
Nauczyciel int not null,
Przedmiot int not null,
constraint fk_nauczycielNP foreign key (Nauczyciel) references Nauczyciel(idNauczyciela),
constraint fk_przedmiotNP foreign key (Przedmiot) references Przedmiot(idPrzedmiotu)
);

create table Profil
(idProfilu int not null primary key,
Nazwa varchar(30)
);

create table Klasa
(idKlasy int not null primary key,
Nazwa varchar(30),
Profil int not null,
constraint fk_profilKlasa foreign key (Profil) references Profil(idProfilu),
Rok int not null,
Wychowawca int,
constraint fk_wychowawcaKlasa foreign key (Wychowawca) references Nauczyciel(idNauczyciela),
);

create table Lekcja
(idLekcji int not null primary key,
Dzieñ varchar(20) constraint ck_dzien CHECK (Dzieñ in ('pon', 'wt', 'œr', 'czw', 'pt')),
Godzina time(0) not null,
Klasa int not null,
constraint fk_profilLekcja foreign key (Klasa) references Klasa(idKlasy),
Przedmiot int not null,
constraint fk_PrzedmiotLekcja foreign key (Przedmiot) references Przedmiot(idPrzedmiotu),
Nauczyciel int not null,
constraint fk_nauczycielLekcja foreign key (Nauczyciel) references Nauczyciel(idNauczyciela),
);

create table Uczeñ
(idUcznia int not null primary key,
Imiê varchar(20) CONSTRAINT ck_imieUczeñ CHECK (Imiê like '[A-Z]%'),
Nazwisko varchar(30) CONSTRAINT ck_nazwiskoUczeñ CHECK (nazwisko like '[A-Z]%'),
Klasa int not null,
constraint fk_klasaUczeñ foreign key (Klasa) references Klasa(idKlasy),
PESEL varchar(11) not null CONSTRAINT ck_peselUczeñ CHECK (PESEL like '[0-9]%'),
Ulica varchar(50),
nrDomu int,
nrMieszkania int,
imiêOjca varchar(20) CONSTRAINT ck_imieOjcaUczeñ CHECK (imiêOjca like '[A-Z]%'),
imiêMatki varchar(20) CONSTRAINT ck_imieMatkiUczeñ CHECK (imiêMatki like '[A-Z]%'),
Aktywny bit,
);

create table PrzedmiotProfil
(Przedmiot int not null,
Profil int not null,
primary key(Przedmiot, Profil),
constraint fk_przedmiotPP foreign key (Przedmiot) references Przedmiot(idPrzedmiotu),
constraint fk_profilPP foreign key (Profil) references Profil(idProfilu),
);

create table Ocena
(idOceny int not null primary key,
NauczycielPrzedmiot int not null,
constraint fk_nauczycielPrzedmiotOcena foreign key (NauczycielPrzedmiot) references NauczycielPrzedmiot(idPary),
Uczeñ int not null,
constraint fk_uczeñOcena foreign key (Uczeñ) references Uczeñ(idUcznia),
Wartoœæ float not null,
Waga int not null,
Kategoria varchar(100),
Koñcowa bit,
);

-- wstawianie danych do tabel

insert into Nauczyciel
values(1,'Jan', 'Kowalski', 'S³oneczna', 15, 2, 'dyrektor', 1)
insert into Nauczyciel
values(2,'Adam', 'Nowak', 'Koniczynowa', 5, 12, 'brak', 1)
insert into Nauczyciel
values(3,'Maria', 'Halska', 'Warmiñska', 11, 5, 'wicedyrektor', 1)
insert into Nauczyciel
values(4,'Alicja', 'Krajewska', 'Poznañska', 1, 2, 'brak', 1)

insert into Przedmiot
values(1,'Jêzyk polski', 'podstawowy', 5, 1)
insert into Przedmiot
values(2,'Jêzyk polski', 'rozszerzony', 7, 1)
insert into Przedmiot
values(3,'Matematyka', 'podstawowy', 4, 1)
insert into Przedmiot
values(4,'Matematyka', 'rozszerzony', 6, 1)
insert into Przedmiot
values(5,'Informatyka', 'rozszerzony', 2, 1)

insert into NauczycielPrzedmiot
values(1,1,3)
insert into NauczycielPrzedmiot
values(2,1,4)
insert into NauczycielPrzedmiot
values(3,2,1)
insert into NauczycielPrzedmiot
values(4,2,2)
insert into NauczycielPrzedmiot
values(5,3,1)
insert into NauczycielPrzedmiot
values(6,4,3)
insert into NauczycielPrzedmiot
values(7,4,5)

insert into Profil
values (1,'mat-fiz')
insert into Profil
values (2,'human')
insert into Profil
values (3,'bio-chem')
insert into Profil
values (4,'mat-geo')

insert into Klasa
values (1,'A', 1, 1, 1)
insert into Klasa
values (2,'B', 2, 3, 4)
insert into Klasa
values (3,'C', 3, 2, 2)
insert into Klasa
values (4,'D', 4, 1, 3)

insert into Lekcja
values (1,'pon', '8:00', 1, 1, 3)
insert into Lekcja
values (2,'wt', '8:55', 2, 3, 1)
insert into Lekcja
values (3,'œr', '9:50', 3, 1, 2)
insert into Lekcja
values (4,'czw', '11:45', 4, 4, 1)

insert into Uczeñ
values (1,'Alicja', 'Maliñska', 1, '98110211346', 'Koœciuszki', 2, 5, 'Jacek', 'Maria',1)
insert into Uczeñ
values (2,'Maria', 'Adamczak', 2, '97021536971', 'Fredry', 36, 11, 'Mateusz', 'Ewa',1)
insert into Uczeñ
values (3,'Micha³', 'Nowakowski', 3, '96031411233', '£¹kowa', 2, 2, 'Stefan', 'Agnieszka',1)

insert into PrzedmiotProfil
values (1,1)
insert into PrzedmiotProfil
values (1,4)
insert into PrzedmiotProfil
values (2,2)
insert into PrzedmiotProfil
values (2,3)
insert into PrzedmiotProfil
values (3,1)
insert into PrzedmiotProfil
values (4,4)

insert into Ocena
values (1, 2, 1, 4.5, 2, 'sprawdzian',0)
insert into Ocena
values (2, 2, 2, 3, 4, 'praca klasowa nr 1',0)
insert into Ocena
values (3, 3, 1, 5, 1, 'kartkówka',0)
insert into Ocena
values (4, 2, 1, 3, 2, 'sprawdzian',0)
insert into Ocena
values (5, 2, 1, 6, 2, 'sprawdzian',0)
insert into Ocena
values (6, 1, 3, 1, 2, 'sprawdzian',0)
insert into Ocena
values (7, 3, 3, 1, 2, 'kartkówka',0)
insert into Ocena
values (8, 7, 3, 1.5, 5, 'praca klasowa',0)

-- wyœwietlanie tabel
select * from Nauczyciel
select * from Przedmiot
select * from NauczycielPrzedmiot
select * from Profil
select * from Klasa
select * from Lekcja
select * from Uczeñ
select * from PrzedmiotProfil
select * from Ocena