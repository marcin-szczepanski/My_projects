package main;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.List;
import java.util.Scanner;
import main.objects.Audiobook;
import main.objects.Book;
import main.objects.Ebook;
import main.objects.Paper;
import main.objects.Statistic;
import main.objects.Table;

public class Main {
	
	static Scanner scanner=new Scanner(System.in);
	static Scanner s=new Scanner(System.in);
	
	public static void info() {
		System.out.println("Aby wczyta� aktualn� baz� ksi��ek, wci�nij 1 a nast�pnie ENTER.");
		System.out.println("Aby doda� ksi��k�, wci�nij 2 a nast�pnie ENTER.");
		System.out.println("Aby edytowa� ksi��k�, wci�nij 3 a nast�pnie ENTER.");
		System.out.println("Aby usun�� ksi��k� wci�nij 4 a nast�pnie ENTER.");
		System.out.println("Aby wy�wietli� statystyki wci�nij 5 a nast�pnie ENTER.");
	}
	
	public static void read(Table t) {
		if (t.getRowsNum()==0) {
			System.out.println("Baza jest pusta!");
		}
		else {
			String row="Stan;Tytu�;Autor;Gatunek;Ilo�� stron;Wydawnictwo;Rok wydania;Typ ksi��ki;Format;Ok�adka;Rozmiar";
			List<String> list = new ArrayList<String>(Arrays.asList(row.split(";")));
			System.out.println("Lp. "+list.toString());
			int n=t.getRowsNum();
			for (int i=0; i<n; i++) {
				List<String> lists=t.getRow(i);
				System.out.println((i+1)+". "+lists.toString());
			}
		}
	}
	
	public static <T> T addInfoBook(T book) {
		System.out.println("Podaj stan ksi��ki. W TRAKCIE CZYTANIA - 1, PRZECZYTANE - 2, NIEPRZECZYTANE - 3, DO KUPIENIA - 4.");
		boolean y=true;
		while (y) {
			String ans=scanner.next();
			if(ans.equals("1")) {
				((Book) book).setState("W TRAKCIE CZYTANIA");
				y=false;
			}
			else if (ans.equals("2")) {
				((Book) book).setState("PRZECZYTANE");
				y=false;
			}
			else if (ans.equals("3")) {
				((Book) book).setState("NIEPRZECZYTANE");
				y=false;
			}
			else if (ans.equals("4")) {
				((Book) book).setState("DO KUPIENIA");
				y=false;
			}
			else {
				System.out.println("Wprowadzi�e� b��dny znak. Spr�buj ponownie.");
			}
		}
		System.out.println("Podaj tytu� ksi��ki:");
		((Book) book).setTitle(s.nextLine());
		System.out.println("Podaj autora ksi��ki:");
		((Book) book).setAuthor(s.nextLine());
		System.out.println("Podaj gatunek:");
		((Book) book).setGenre(s.nextLine());
		System.out.println("Podaj wydawnictwo:");
		((Book) book).setPublication(s.nextLine());
		System.out.println("Ile stron ma ksi��ka?");
		((Book) book).setNumberOfPages(s.nextLine());
		System.out.println("Podaj rok wydania:");
		((Book) book).setDateOfPublication(s.nextLine());
		return book;
	}
	
	public static <T> List<String> addToTable(Table t, T book) {
		List<String> list=new ArrayList<String>();
		list.add(((Book) book).getState());
		list.add(((Book) book).getTitle());
		list.add(((Book) book).getAuthor());
		list.add(((Book) book).getGenre());
		list.add(((Book) book).getNumberOfPages());
		list.add(((Book) book).getPublication());
		list.add(((Book) book).getDateOfPublication());
		list.add(((Book) book).getClassType());
		list.add(((Book) book).getFormat());
		list.add(((Book) book).getCover());
		list.add(((Book) book).getSize());
		return list;
	}
	
	public static List<String> addItem(Table t) {
		List<String> list=new ArrayList<String>();
		System.out.println("Podaj typ ksi��ki: 1 - ksi��ka w wersji papierowej, 2 - e-book, 3 - audiobook.");
		boolean x=true;
		while (x) {
			String answer=scanner.next();
			if(answer.equals("1")) {
				Paper book=new Paper();
				book=addInfoBook(book);
				System.out.println("Jakiego formatu jest ksi��ka? A4 - 1, A5 - 2, B5 - 3, B6 - 4, INNY - 5");
				String ansP;
				boolean xx=true;
				while (xx) {
					ansP=scanner.next();
					xx=false;
					if (ansP.equals("1")) {
						book.setFormat("A4");
					}
					else if (ansP.equals("2")) {
						book.setFormat("A5");
					}
					else if (ansP.equals("3")) {
						book.setFormat("B5");
					}
					else if (ansP.equals("4")) {
						book.setFormat("B6");
					}
					else if (ansP.equals("5")) {
						book.setFormat("inny");
					}
					else {
						System.out.println("Wprowadzi�e� b��dny znak! Spr�buj ponownie.");
						xx=true;
					}
				}
				System.out.println("Jakiego typu jest ok�adka ksi��ki? 1 - mi�kka, 2 - twarda");
				xx=true;
				String ansCov;
				while(xx) {
					ansCov=scanner.next();
					xx=false;
					if (ansCov.equals("1")) {
						book.setCover("mi�kka");
					}
					else if (ansCov.equals("2")) {
						book.setCover("twarda");
					}
					else {
						System.out.println("Wprowadzi�e� b��dny znak! Spr�buj ponownie.");
						xx=true;
					}
				}
				list=addToTable(t,book);
				x=false;
			}
			else if (answer.equals("2")) {
				Ebook book=new Ebook();
				book=addInfoBook(book);
				System.out.println("Jakiego formatu jest ksi��ka? pdf - 1, mobi - 2, ePub - 3, inny - 4");
				String ansP;
				boolean xx=true;
				while (xx) {
					ansP=scanner.next();
					xx=false;
					if (ansP.equals("1")) {
						book.setFormat("pdf");
					}
					else if (ansP.equals("2")) {
						book.setFormat("mobi");
					}
					else if (ansP.equals("3")) {
						book.setFormat("ePub");
					}
					else if (ansP.equals("4")) {
						book.setFormat("inny");
					}
					else {
						System.out.println("Wprowadzi�e� b��dny znak! Spr�buj ponownie.");
						xx=true;
					}
				}
				System.out.println("Podaj rozmiar ksi��ki (w dowolnej jednostce):");
				book.setSize(s.nextLine());
				list=addToTable(t,book);
				x=false;
			}
			else if (answer.equals("3")) {
				Audiobook book=new Audiobook();
				book=addInfoBook(book);
				System.out.println("Jakiego formatu jest ksi��ka? mp3 - 1, ogg - 2, cd - 3, kaseta - 4, inny - 5");
				String ansP;
				boolean xx=true;
				while (xx) {
					ansP=scanner.next();
					xx=false;
					if (ansP.equals("1")) {
						book.setFormat("mp3");
					}
					else if (ansP.equals("2")) {
						book.setFormat("ogg");
					}
					else if (ansP.equals("3")) {
						book.setFormat("CD");
					}
					else if (ansP.equals("4")) {
						book.setFormat("kaseta");
					}
					else if (ansP.equals("5")) {
						book.setFormat("inny");
					}
					else {
						System.out.println("Wprowadzi�e� b��dny znak! Spr�buj ponownie.");
						xx=true;
					}
				}
				System.out.println("Podaj rozmiar ksi��ki (w dowolnej jednostce):");
				book.setSize(s.nextLine());
				list=addToTable(t,book);
				x=false;
			}
			else {
				System.out.println("Wprowadzi�e� b��dny znak. Spr�buj ponownie.");
			}
		}
		return list;
	}
	
	public static void editItem(Table t) {
		System.out.println("Kt�r� pozycj� chcesz edytowa�?");
		read(t);
		try {
			int ans=scanner.nextInt();
			if ((ans<=t.getRowsNum()) && (ans>0)) {
				List<String> list=new ArrayList<String>();
				System.out.println();
				System.out.println("------ Edytowanie pozycji nr: "+ans+". ------");
				list=t.getRow(ans-1);
				List<String> listEdit=new ArrayList<String>();
				String ch;
				boolean boo=true;
				System.out.println("Aktualny stan ksi��ki to: " + list.get(0)+". Czy chcesz to edytowa�? (tak - 1, nie - 2)");
				while(boo) {
					ch=scanner.next();
					if(ch.equals("1")) {
						System.out.println("Podaj now� warto��: W TRAKCIE CZYTANIA - 1, PRZECZYTANE - 2, NIEPRZECZYTANE - 3, DO KUPIENIA - 4.");
						boolean y=true;
						while (y) {
							String answ=scanner.next();
							if(answ.equals("1")) {
								listEdit.add(0, "W TRAKCIE CZYTANIA");
								y=false;
							}
							else if (answ.equals("2")) {
								listEdit.add(0, "PRZECZYTANE");
								y=false;
							}
							else if (answ.equals("3")) {
								listEdit.add(0, "NIEPRZECZYTANE");
								y=false;
							}
							else if (answ.equals("4")) {
								listEdit.add(0, "DO KUPIENIA");
								y=false;
							}
							else {
								System.out.println("Wprowadzi�e� b��dny znak. Spr�buj ponownie.");
							}
						}
						boo=false;
					}
					else if(ch.equals("2")) {
						listEdit.add(0, list.get(0));
						boo=false;
					}
					else {
						System.out.println("Wprowadzi�e� b��dny znak! Spr�buj ponownie.");
					}
				}
				System.out.println("Aktualny tytu� ksi��ki to: " + list.get(1)+". Czy chcesz to edytowa�? (tak - 1, nie - 2)");
				boo=true;
				while(boo) {
					ch=scanner.next();
					if(ch.equals("1")) {
						System.out.println("Podaj now� warto��:");
						listEdit.add(1, s.nextLine());
						boo=false;
					}
					else if(ch.equals("2")) {
						listEdit.add(1, list.get(1));
						boo=false;
					}
					else {
						System.out.println("Wprowadzi�e� b��dny znak! Spr�buj ponownie.");
					}
				}
				System.out.println("Aktualny autor ksi��ki to: " + list.get(2)+". Czy chcesz to edytowa�? (tak - 1, nie - 2)");
				boo=true;
				while(boo) {
					ch=scanner.next();
					if(ch.equals("1")) {
						System.out.println("Podaj now� warto��:");
						listEdit.add(2, s.nextLine());
						boo=false;
					}
					else if(ch.equals("2")) {
						listEdit.add(2, list.get(2));
						boo=false;
					}
					else {
						System.out.println("Wprowadzi�e� b��dny znak! Spr�buj ponownie.");
					}
				}
				System.out.println("Aktualny gatunek ksi��ki to: " + list.get(3)+". Czy chcesz to edytowa�? (tak - 1, nie - 2)");
				boo=true;
				while(boo) {
					ch=scanner.next();
					if(ch.equals("1")) {
						System.out.println("Podaj now� warto��:");
						listEdit.add(3, s.nextLine());
						boo=false;
					}
					else if(ch.equals("2")) {
						listEdit.add(3, list.get(3));
						boo=false;
					}
					else {
						System.out.println("Wprowadzi�e� b��dny znak! Spr�buj ponownie.");
					}
				}
				System.out.println("Aktualna ilo�� stron ksi��ki to: " + list.get(4)+". Czy chcesz to edytowa�? (tak - 1, nie - 2)");
				boo=true;
				while(boo) {
					ch=scanner.next();
					if(ch.equals("1")) {
						System.out.println("Podaj now� warto��:");
						listEdit.add(4, s.nextLine());
						boo=false;
					}
					else if(ch.equals("2")) {
						listEdit.add(4, list.get(4));
						boo=false;
					}
					else {
						System.out.println("Wprowadzi�e� b��dny znak! Spr�buj ponownie.");
					}
				}
				System.out.println("Aktualne wydawnictwo ksi��ki to: " + list.get(5)+". Czy chcesz to edytowa�? (tak - 1, nie - 2)");
				boo=true;
				while(boo) {
					ch=scanner.next();
					if(ch.equals("1")) {
						System.out.println("Podaj now� warto��:");
						listEdit.add(5, s.nextLine());
						boo=false;
					}
					else if(ch.equals("2")) {
						listEdit.add(5, list.get(5));
						boo=false;
					}
					else {
						System.out.println("Wprowadzi�e� b��dny znak! Spr�buj ponownie.");
					}
				}
				System.out.println("Aktualny rok wydania ksi��ki to: " + list.get(6)+". Czy chcesz to edytowa�? (tak - 1, nie - 2)");
				boo=true;
				while(boo) {
					ch=scanner.next();
					if(ch.equals("1")) {
						System.out.println("Podaj now� warto��:");
						listEdit.add(6, s.nextLine());
						boo=false;
					}
					else if(ch.equals("2")) {
						listEdit.add(6, list.get(6));
						boo=false;
					}
					else {
						System.out.println("Wprowadzi�e� b��dny znak! Spr�buj ponownie.");
					}
				}
				boo=true;
				System.out.println("Aktualny typ ksi��ki to: " + list.get(7)+". Czy chcesz to edytowa�? (tak - 1, nie - 2)");
				while(boo) {
					ch=scanner.next();
					if(ch.equals("1")) {
						System.out.println("Podaj nowy typ ksi��ki: 1 - ksi��ka w wersji papierowej, 2 - e-book, 3 - audiobook.");
						boolean x=true;
						while (x) {
							String answer=scanner.next();
							if(answer.equals("1")) {
								listEdit.add(7, "wersja papierowa");
								System.out.println("Jakiego formatu jest ksi��ka? A4 - 1, A5 - 2, B5 - 3, B6 - 4, INNY - 5");
								String ansP;
								boolean xx=true;
								while (xx) {
									ansP=scanner.next();
									xx=false;
									if (ansP.equals("1")) {
										listEdit.add(8, "A4");
									}
									else if (ansP.equals("2")) {
										listEdit.add(8, "A5");
									}
									else if (ansP.equals("3")) {
										listEdit.add(8, "B5");
									}
									else if (ansP.equals("4")) {
										listEdit.add(8, "B6");
									}
									else if (ansP.equals("5")) {
										listEdit.add(8, "inny");
									}
									else {
										System.out.println("Wprowadzi�e� b��dny znak! Spr�buj ponownie.");
										xx=true;
									}
								}
								System.out.println("Jakiego typu jest ok�adka ksi��ki? 1 - mi�kka, 2 - twarda");
								String ansCov;
								xx=true;
								while(xx) {
									ansCov=scanner.next();
									xx=false;
									if (ansCov.equals("1")) {
										listEdit.add(9, "mi�kka");
									}
									else if (ansCov.equals("2")) {
										listEdit.add(9,"twarda");
									}
									else {
										System.out.println("Wprowadzi�e� b��dny znak! Spr�buj ponownie.");
										xx=true;
									}
								}
								listEdit.add(10, "nie dotyczy");
								x=false;
							}
							else if (answer.equals("2")) {
								listEdit.add(7, "e-book");
								System.out.println("Jakiego formatu jest ksi��ka? pdf - 1, mobi - 2, ePub - 3, inny - 4");
								String ansP;
								boolean xx=true;
								while (xx) {
									ansP=scanner.next();
									xx=false;
									if (ansP.equals("1")) {
										listEdit.add(8, "pdf");
									}
									else if (ansP.equals("2")) {
										listEdit.add(8, "mobi");
									}
									else if (ansP.equals("3")) {
										listEdit.add(8, "ePub");
									}
									else if (ansP.equals("4")) {
										listEdit.add(8, "inny");
									}
									else {
										System.out.println("Wprowadzi�e� b��dny znak! Spr�buj ponownie.");
										xx=true;
									}
								}
								x=false;
							}
							else if (answer.equals("3")) {
								listEdit.add(7, "audiobook");
								System.out.println("Jakiego formatu jest ksi��ka? mp3 - 1, ogg - 2, cd - 3, kaseta - 4, inny - 5");
								String ansP;
								boolean xx=true;
								while (xx) {
										ansP=scanner.next();
										xx=false;
										if (ansP.equals("1")) {
											listEdit.add(8, "mp3");
										}
										else if (ansP.equals("2")) {
											listEdit.add(8, "ogg");
										}
										else if (ansP.equals("3")) {
											listEdit.add(8, "CD");
										}
										else if (ansP.equals("4")) {
											listEdit.add(8, "kaseta");
										}
										else if (ansP.equals("5")) {
											listEdit.add(8, "inny");
										}
										else {
											System.out.println("Wprowadzi�e� b��dny znak! Spr�buj ponownie.");
											xx=true;
										}
									}
								x=false;
							}
							else {
								System.out.println("Wprowadzi�e� b��dny znak. Spr�buj ponownie.");
							}
							if ((answer.equals("2"))||(answer.equals("3"))) {
								listEdit.add(9, "nie dotyczy");
								System.out.println("Podaj rozmiar ksi��ki (w dowolnej jednostce):");
								listEdit.add(10, s.nextLine());
							}
						}
						boo=false;
					}
					else if(ch.equals("2")) {
						listEdit.add(7, list.get(7));
						if(list.get(7).equals("wersja papierowa")) {
							boolean boo1=true;
							System.out.println("Aktualny format ksi��ki to: "+list.get(8)+". Czy chcesz to edytowa�? (tak - 1, nie - 2)");
							while(boo1) {
								ch=scanner.next();
								if(ch.equals("1")) {
									System.out.println("Jakiego formatu jest ksi��ka? A4 - 1, A5 - 2, B5 - 3, B6 - 4, INNY - 5");
									String ansP;
									boolean xx=true;
									while (xx) {
										ansP=scanner.next();
										xx=false;
										if (ansP.equals("1")) {
											listEdit.add(8, "A4");
										}
										else if (ansP.equals("2")) {
											listEdit.add(8, "A5");
										}
										else if (ansP.equals("3")) {
											listEdit.add(8, "B5");
										}
										else if (ansP.equals("4")) {
											listEdit.add(8, "B6");
										}
										else if (ansP.equals("5")) {
											listEdit.add(8, "inny");
										}
										else {
											System.out.println("Wprowadzi�e� b��dny znak! Spr�buj ponownie.");
											xx=true;
										}
									}
									boo1=false;
								}
								else if(ch.equals("2")) {
									listEdit.add(8, list.get(8));
									boo1=false;
								}
								else {
									System.out.println("Wprowadzi�e� b��dny znak! Spr�buj ponownie.");
								}
							}
							boo1=true;
							System.out.println("Aktualna ok�adka ksi��ki to: "+list.get(9)+". Czy chcesz to edytowa�? (tak - 1, nie - 2)");
							while(boo1) {
								ch=scanner.next();
								if(ch.equals("1")) {
									System.out.println("Jakiego typu jest ok�adka ksi��ki? 1 - mi�kka, 2 - twarda");
									String ansCov;
									boolean xx=true;
									while(xx) {
										ansCov=scanner.next();
										xx=false;
										if (ansCov.equals("1")) {
											listEdit.add(9, "mi�kka");
										}
										else if (ansCov.equals("2")) {
											listEdit.add(9,"twarda");
										}
										else {
											System.out.println("Wprowadzi�e� b��dny znak! Spr�buj ponownie.");
											xx=true;
										}
									}
									boo1=false;
								}
								else if(ch.equals("2")) {
									listEdit.add(9, list.get(9));
									boo1=false;
								}
								else {
									System.out.println("Wprowadzi�e� b��dny znak! Spr�buj ponownie.");
								}
							}
							listEdit.add(10, list.get(10));
						}
						else if (list.get(7).equals("e-book")) {
							boolean boo1=true;
							System.out.println("Aktualny format ksi��ki to: "+list.get(8)+". Czy chcesz to edytowa�? (tak - 1, nie - 2)");
							while(boo1) {
								ch=scanner.next();
								if(ch.equals("1")) {
									System.out.println("Jakiego formatu jest ksi��ka? pdf - 1, mobi - 2, ePub - 3, inny - 4");
									String ansP;
									boolean xx=true;
									while (xx) {
										ansP=scanner.next();
										xx=false;
										if (ansP.equals("1")) {
											listEdit.add(8, "pdf");
										}
										else if (ansP.equals("2")) {
											listEdit.add(8, "mobi");
										}
										else if (ansP.equals("3")) {
											listEdit.add(8, "ePub");
										}
										else if (ansP.equals("4")) {
											listEdit.add(8, "inny");
										}
										else {
											System.out.println("Wprowadzi�e� b��dny znak! Spr�buj ponownie.");
											xx=true;
										}
									}
									boo1=false;
								}
								else if(ch.equals("2")) {
									listEdit.add(8, list.get(8));
									boo1=false;
								}
								else {
									System.out.println("Wprowadzi�e� b��dny znak! Spr�buj ponownie.");
								}
							}
						}
						else if (list.get(7).equals("audiobook")) {
							boolean boo1=true;
							System.out.println("Aktualny format ksi��ki to: "+list.get(8)+". Czy chcesz to edytowa�? (tak - 1, nie - 2)");
							while(boo1) {
								ch=scanner.next();
								if(ch.equals("1")) {
									System.out.println("Jakiego formatu jest ksi��ka? mp3 - 1, ogg - 2, cd - 3, kaseta - 4, inny - 5");
									String ansP;
									boolean xx=true;
									while (xx) {
										ansP=scanner.next();
										xx=false;
										if (ansP.equals("1")) {
											listEdit.add(8, "mp3");
										}
										else if (ansP.equals("2")) {
											listEdit.add(8, "ogg");
										}
										else if (ansP.equals("3")) {
											listEdit.add(8, "CD");
										}
										else if (ansP.equals("4")) {
											listEdit.add(8, "kaseta");
										}
										else if (ansP.equals("5")) {
											listEdit.add(8, "inny");
										}
										else {
											System.out.println("Wprowadzi�e� b��dny znak! Spr�buj ponownie.");
											xx=true;
										}
									}
									boo1=false;
								}
								else if(ch.equals("2")) {
									listEdit.add(8, list.get(8));
									boo1=false;
								}
								else {
									System.out.println("Wprowadzi�e� b��dny znak! Spr�buj ponownie.");
								}
							}
						}
						if(!(list.get(7).equals("wersja papierowa"))) {
							listEdit.add(9, list.get(9));
							System.out.println("Ustaw rozmiar ksi��ki:");
							listEdit.add(10, s.nextLine());
						}
						boo=false;
					}
					else {
						System.out.println("Wprowadzi�e� b��dny znak! Spr�buj ponownie.");
					}
				}
				t.editRow(ans-1,listEdit);
				System.out.println("Pozycja zosta�a edytowana.");
				read(t);
			}
			else {
				System.out.println("Nie ma pozycji o takim numerze!");
			}
		} catch (InputMismatchException e) {
			System.out.println("Podany znak musi by� liczb� naturaln�!");
		}
	}
	
	public static void deleteItem(Table t) {
		System.out.println("Kt�r� pozycj� chcesz usun��?");
		read(t);
		try {
			int ans=scanner.nextInt();
			if ((ans<=t.getRowsNum()) && (ans>0)) {
				t.deleteRow(ans-1);
				System.out.println("Pozycja zosta�a usuni�ta z bazy.");
				read(t);
			}
			else {
				System.out.println("Nie ma pozycji o takim numerze!");
			}
		} catch (InputMismatchException e) {
			System.out.println("Podany znak musi by� liczb� naturaln�!");
		}
	}
	
	public static int stats(List<List<String>> listOfLists, int index, String text) {
		Statistic readNow = new Statistic(index,text);
		int k=readNow.howManySearched(listOfLists);
		return k;
	}
	
	public static void seeStatistics(Table t) {
		int n=t.getRowsNum();
		List<List<String>> listOfLists = new ArrayList<List<String>>();
		for (int i=0; i<n; i++) {
			List<String> singleList=t.getRow(i);
			listOfLists.add(singleList);
		}
		System.out.println("Czytane ksi��ki: "+stats(listOfLists,0,"W TRAKCIE CZYTANIA")+".");
		System.out.println("Przeczytane ksi��ki: "+stats(listOfLists,0,"PRZECZYTANE")+".");
		System.out.println("Nieprzeczytane ksi��ki: "+stats(listOfLists,0,"NIEPRZECZYTANE")+".");
		System.out.println("Ksi��ki do kupienia: "+stats(listOfLists,0,"DO KUPIENIA")+".");
		System.out.println();
		System.out.println("Ksi��ki w wersji papierowej: "+stats(listOfLists,7,"wersja papierowa")+".");
		System.out.println("E-booki: "+stats(listOfLists,7,"e-book")+".");
		System.out.println("Audiobooki: "+stats(listOfLists,7,"audiobook")+".");
		System.out.println();
		System.out.println("Ksi��ek razem: "+n+".");
	}
	
	/* Main function */
	public static void main(String[] args) {
		System.out.println("Witaj w programie Baza ksi��ek!");
		info();
		boolean x=true;
		while (x) {
			String answer=scanner.next();
			Table t=new Table("baza.txt");
			if (answer.equals("1")) {
				System.out.println();
				read(t);
				System.out.println();
				System.out.println("Je�li chcesz dzia�a� dalej wci�nij 0 a nast�pnie ENTER, w przeciwnym wypadku wpisz dowolny klawisz i ENTER.");
				String a=scanner.next();
				if (a.equals("0")) {
					x=true;
					info();
				}
				else {
					x=false;
				}
			}
			else if (answer.equals("2")) {
				List<String> list=new ArrayList<String>();
				System.out.println();
				System.out.println("------ Dodawanie nowej pozycji ------");
				list=addItem(t);
				t.insertRow(list);
				System.out.println("Dodano pozycj� do bazy.");
				read(t);
				System.out.println();
				System.out.println("Je�li chcesz dzia�a� dalej wci�nij 0 a nast�pnie ENTER, w przeciwnym wypadku wpisz dowolny klawisz i ENTER.");
				String a=scanner.next();
				if (a.equals("0")) {
					x=true;
					info();
				}
				else {
					x=false;
				}
			}
			else if (answer.equals("3")) {
				System.out.println();
				editItem(t);
				System.out.println();
				System.out.println("Je�li chcesz dzia�a� dalej wci�nij 0 a nast�pnie ENTER, w przeciwnym wypadku wpisz dowolny klawisz i ENTER.");
				String a=scanner.next();
				if (a.equals("0")) {
					x=true;
					info();
				}
				else {
					x=false;
				}
			}
			else if (answer.equals("4")) {
				System.out.println();
				deleteItem(t);
				System.out.println();
				System.out.println("Je�li chcesz dzia�a� dalej wci�nij 0 a nast�pnie ENTER, w przeciwnym wypadku wpisz dowolny klawisz i ENTER.");
				String a=scanner.next();
				if (a.equals("0")) {
					x=true;
					info();
				}
				else {
					x=false;
				}
			}
			else if (answer.equals("5")) {
				System.out.println();
				seeStatistics(t);
				System.out.println();
				System.out.println("Je�li chcesz dzia�a� dalej wci�nij 0 a nast�pnie ENTER, w przeciwnym wypadku wpisz dowolny klawisz i ENTER.");
				String a=scanner.next();
				if (a.equals("0")) {
					x=true;
					info();
				}
				else {
					x=false;
				}
			}
			else {
				System.out.println("Wpisa�e� b��dny znak! Spr�buj ponownie.");
			}
		}
		scanner.close();
		s.close();
	}
}