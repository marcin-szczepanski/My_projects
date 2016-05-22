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
		System.out.println("Aby wczytaæ aktualn¹ bazê ksi¹¿ek, wciœnij 1 a nastêpnie ENTER.");
		System.out.println("Aby dodaæ ksi¹¿kê, wciœnij 2 a nastêpnie ENTER.");
		System.out.println("Aby edytowaæ ksi¹¿kê, wciœnij 3 a nastêpnie ENTER.");
		System.out.println("Aby usun¹æ ksi¹¿kê wciœnij 4 a nastêpnie ENTER.");
		System.out.println("Aby wyœwietliæ statystyki wciœnij 5 a nastêpnie ENTER.");
	}
	
	public static void read(Table t) {
		if (t.getRowsNum()==0) {
			System.out.println("Baza jest pusta!");
		}
		else {
			String row="Stan;Tytu³;Autor;Gatunek;Iloœæ stron;Wydawnictwo;Rok wydania;Typ ksi¹¿ki;Format;Ok³adka;Rozmiar";
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
		System.out.println("Podaj stan ksi¹¿ki. W TRAKCIE CZYTANIA - 1, PRZECZYTANE - 2, NIEPRZECZYTANE - 3, DO KUPIENIA - 4.");
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
				System.out.println("Wprowadzi³eœ b³êdny znak. Spróbuj ponownie.");
			}
		}
		System.out.println("Podaj tytu³ ksi¹¿ki:");
		((Book) book).setTitle(s.nextLine());
		System.out.println("Podaj autora ksi¹¿ki:");
		((Book) book).setAuthor(s.nextLine());
		System.out.println("Podaj gatunek:");
		((Book) book).setGenre(s.nextLine());
		System.out.println("Podaj wydawnictwo:");
		((Book) book).setPublication(s.nextLine());
		System.out.println("Ile stron ma ksi¹¿ka?");
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
		System.out.println("Podaj typ ksi¹¿ki: 1 - ksi¹¿ka w wersji papierowej, 2 - e-book, 3 - audiobook.");
		boolean x=true;
		while (x) {
			String answer=scanner.next();
			if(answer.equals("1")) {
				Paper book=new Paper();
				book=addInfoBook(book);
				System.out.println("Jakiego formatu jest ksi¹¿ka? A4 - 1, A5 - 2, B5 - 3, B6 - 4, INNY - 5");
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
						System.out.println("Wprowadzi³eœ b³êdny znak! Spróbuj ponownie.");
						xx=true;
					}
				}
				System.out.println("Jakiego typu jest ok³adka ksi¹¿ki? 1 - miêkka, 2 - twarda");
				xx=true;
				String ansCov;
				while(xx) {
					ansCov=scanner.next();
					xx=false;
					if (ansCov.equals("1")) {
						book.setCover("miêkka");
					}
					else if (ansCov.equals("2")) {
						book.setCover("twarda");
					}
					else {
						System.out.println("Wprowadzi³eœ b³êdny znak! Spróbuj ponownie.");
						xx=true;
					}
				}
				list=addToTable(t,book);
				x=false;
			}
			else if (answer.equals("2")) {
				Ebook book=new Ebook();
				book=addInfoBook(book);
				System.out.println("Jakiego formatu jest ksi¹¿ka? pdf - 1, mobi - 2, ePub - 3, inny - 4");
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
						System.out.println("Wprowadzi³eœ b³êdny znak! Spróbuj ponownie.");
						xx=true;
					}
				}
				System.out.println("Podaj rozmiar ksi¹¿ki (w dowolnej jednostce):");
				book.setSize(s.nextLine());
				list=addToTable(t,book);
				x=false;
			}
			else if (answer.equals("3")) {
				Audiobook book=new Audiobook();
				book=addInfoBook(book);
				System.out.println("Jakiego formatu jest ksi¹¿ka? mp3 - 1, ogg - 2, cd - 3, kaseta - 4, inny - 5");
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
						System.out.println("Wprowadzi³eœ b³êdny znak! Spróbuj ponownie.");
						xx=true;
					}
				}
				System.out.println("Podaj rozmiar ksi¹¿ki (w dowolnej jednostce):");
				book.setSize(s.nextLine());
				list=addToTable(t,book);
				x=false;
			}
			else {
				System.out.println("Wprowadzi³eœ b³êdny znak. Spróbuj ponownie.");
			}
		}
		return list;
	}
	
	public static void editItem(Table t) {
		System.out.println("Któr¹ pozycjê chcesz edytowaæ?");
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
				System.out.println("Aktualny stan ksi¹¿ki to: " + list.get(0)+". Czy chcesz to edytowaæ? (tak - 1, nie - 2)");
				while(boo) {
					ch=scanner.next();
					if(ch.equals("1")) {
						System.out.println("Podaj now¹ wartoœæ: W TRAKCIE CZYTANIA - 1, PRZECZYTANE - 2, NIEPRZECZYTANE - 3, DO KUPIENIA - 4.");
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
								System.out.println("Wprowadzi³eœ b³êdny znak. Spróbuj ponownie.");
							}
						}
						boo=false;
					}
					else if(ch.equals("2")) {
						listEdit.add(0, list.get(0));
						boo=false;
					}
					else {
						System.out.println("Wprowadzi³eœ b³êdny znak! Spróbuj ponownie.");
					}
				}
				System.out.println("Aktualny tytu³ ksi¹¿ki to: " + list.get(1)+". Czy chcesz to edytowaæ? (tak - 1, nie - 2)");
				boo=true;
				while(boo) {
					ch=scanner.next();
					if(ch.equals("1")) {
						System.out.println("Podaj now¹ wartoœæ:");
						listEdit.add(1, s.nextLine());
						boo=false;
					}
					else if(ch.equals("2")) {
						listEdit.add(1, list.get(1));
						boo=false;
					}
					else {
						System.out.println("Wprowadzi³eœ b³êdny znak! Spróbuj ponownie.");
					}
				}
				System.out.println("Aktualny autor ksi¹¿ki to: " + list.get(2)+". Czy chcesz to edytowaæ? (tak - 1, nie - 2)");
				boo=true;
				while(boo) {
					ch=scanner.next();
					if(ch.equals("1")) {
						System.out.println("Podaj now¹ wartoœæ:");
						listEdit.add(2, s.nextLine());
						boo=false;
					}
					else if(ch.equals("2")) {
						listEdit.add(2, list.get(2));
						boo=false;
					}
					else {
						System.out.println("Wprowadzi³eœ b³êdny znak! Spróbuj ponownie.");
					}
				}
				System.out.println("Aktualny gatunek ksi¹¿ki to: " + list.get(3)+". Czy chcesz to edytowaæ? (tak - 1, nie - 2)");
				boo=true;
				while(boo) {
					ch=scanner.next();
					if(ch.equals("1")) {
						System.out.println("Podaj now¹ wartoœæ:");
						listEdit.add(3, s.nextLine());
						boo=false;
					}
					else if(ch.equals("2")) {
						listEdit.add(3, list.get(3));
						boo=false;
					}
					else {
						System.out.println("Wprowadzi³eœ b³êdny znak! Spróbuj ponownie.");
					}
				}
				System.out.println("Aktualna iloœæ stron ksi¹¿ki to: " + list.get(4)+". Czy chcesz to edytowaæ? (tak - 1, nie - 2)");
				boo=true;
				while(boo) {
					ch=scanner.next();
					if(ch.equals("1")) {
						System.out.println("Podaj now¹ wartoœæ:");
						listEdit.add(4, s.nextLine());
						boo=false;
					}
					else if(ch.equals("2")) {
						listEdit.add(4, list.get(4));
						boo=false;
					}
					else {
						System.out.println("Wprowadzi³eœ b³êdny znak! Spróbuj ponownie.");
					}
				}
				System.out.println("Aktualne wydawnictwo ksi¹¿ki to: " + list.get(5)+". Czy chcesz to edytowaæ? (tak - 1, nie - 2)");
				boo=true;
				while(boo) {
					ch=scanner.next();
					if(ch.equals("1")) {
						System.out.println("Podaj now¹ wartoœæ:");
						listEdit.add(5, s.nextLine());
						boo=false;
					}
					else if(ch.equals("2")) {
						listEdit.add(5, list.get(5));
						boo=false;
					}
					else {
						System.out.println("Wprowadzi³eœ b³êdny znak! Spróbuj ponownie.");
					}
				}
				System.out.println("Aktualny rok wydania ksi¹¿ki to: " + list.get(6)+". Czy chcesz to edytowaæ? (tak - 1, nie - 2)");
				boo=true;
				while(boo) {
					ch=scanner.next();
					if(ch.equals("1")) {
						System.out.println("Podaj now¹ wartoœæ:");
						listEdit.add(6, s.nextLine());
						boo=false;
					}
					else if(ch.equals("2")) {
						listEdit.add(6, list.get(6));
						boo=false;
					}
					else {
						System.out.println("Wprowadzi³eœ b³êdny znak! Spróbuj ponownie.");
					}
				}
				boo=true;
				System.out.println("Aktualny typ ksi¹¿ki to: " + list.get(7)+". Czy chcesz to edytowaæ? (tak - 1, nie - 2)");
				while(boo) {
					ch=scanner.next();
					if(ch.equals("1")) {
						System.out.println("Podaj nowy typ ksi¹¿ki: 1 - ksi¹¿ka w wersji papierowej, 2 - e-book, 3 - audiobook.");
						boolean x=true;
						while (x) {
							String answer=scanner.next();
							if(answer.equals("1")) {
								listEdit.add(7, "wersja papierowa");
								System.out.println("Jakiego formatu jest ksi¹¿ka? A4 - 1, A5 - 2, B5 - 3, B6 - 4, INNY - 5");
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
										System.out.println("Wprowadzi³eœ b³êdny znak! Spróbuj ponownie.");
										xx=true;
									}
								}
								System.out.println("Jakiego typu jest ok³adka ksi¹¿ki? 1 - miêkka, 2 - twarda");
								String ansCov;
								xx=true;
								while(xx) {
									ansCov=scanner.next();
									xx=false;
									if (ansCov.equals("1")) {
										listEdit.add(9, "miêkka");
									}
									else if (ansCov.equals("2")) {
										listEdit.add(9,"twarda");
									}
									else {
										System.out.println("Wprowadzi³eœ b³êdny znak! Spróbuj ponownie.");
										xx=true;
									}
								}
								listEdit.add(10, "nie dotyczy");
								x=false;
							}
							else if (answer.equals("2")) {
								listEdit.add(7, "e-book");
								System.out.println("Jakiego formatu jest ksi¹¿ka? pdf - 1, mobi - 2, ePub - 3, inny - 4");
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
										System.out.println("Wprowadzi³eœ b³êdny znak! Spróbuj ponownie.");
										xx=true;
									}
								}
								x=false;
							}
							else if (answer.equals("3")) {
								listEdit.add(7, "audiobook");
								System.out.println("Jakiego formatu jest ksi¹¿ka? mp3 - 1, ogg - 2, cd - 3, kaseta - 4, inny - 5");
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
											System.out.println("Wprowadzi³eœ b³êdny znak! Spróbuj ponownie.");
											xx=true;
										}
									}
								x=false;
							}
							else {
								System.out.println("Wprowadzi³eœ b³êdny znak. Spróbuj ponownie.");
							}
							if ((answer.equals("2"))||(answer.equals("3"))) {
								listEdit.add(9, "nie dotyczy");
								System.out.println("Podaj rozmiar ksi¹¿ki (w dowolnej jednostce):");
								listEdit.add(10, s.nextLine());
							}
						}
						boo=false;
					}
					else if(ch.equals("2")) {
						listEdit.add(7, list.get(7));
						if(list.get(7).equals("wersja papierowa")) {
							boolean boo1=true;
							System.out.println("Aktualny format ksi¹¿ki to: "+list.get(8)+". Czy chcesz to edytowaæ? (tak - 1, nie - 2)");
							while(boo1) {
								ch=scanner.next();
								if(ch.equals("1")) {
									System.out.println("Jakiego formatu jest ksi¹¿ka? A4 - 1, A5 - 2, B5 - 3, B6 - 4, INNY - 5");
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
											System.out.println("Wprowadzi³eœ b³êdny znak! Spróbuj ponownie.");
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
									System.out.println("Wprowadzi³eœ b³êdny znak! Spróbuj ponownie.");
								}
							}
							boo1=true;
							System.out.println("Aktualna ok³adka ksi¹¿ki to: "+list.get(9)+". Czy chcesz to edytowaæ? (tak - 1, nie - 2)");
							while(boo1) {
								ch=scanner.next();
								if(ch.equals("1")) {
									System.out.println("Jakiego typu jest ok³adka ksi¹¿ki? 1 - miêkka, 2 - twarda");
									String ansCov;
									boolean xx=true;
									while(xx) {
										ansCov=scanner.next();
										xx=false;
										if (ansCov.equals("1")) {
											listEdit.add(9, "miêkka");
										}
										else if (ansCov.equals("2")) {
											listEdit.add(9,"twarda");
										}
										else {
											System.out.println("Wprowadzi³eœ b³êdny znak! Spróbuj ponownie.");
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
									System.out.println("Wprowadzi³eœ b³êdny znak! Spróbuj ponownie.");
								}
							}
							listEdit.add(10, list.get(10));
						}
						else if (list.get(7).equals("e-book")) {
							boolean boo1=true;
							System.out.println("Aktualny format ksi¹¿ki to: "+list.get(8)+". Czy chcesz to edytowaæ? (tak - 1, nie - 2)");
							while(boo1) {
								ch=scanner.next();
								if(ch.equals("1")) {
									System.out.println("Jakiego formatu jest ksi¹¿ka? pdf - 1, mobi - 2, ePub - 3, inny - 4");
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
											System.out.println("Wprowadzi³eœ b³êdny znak! Spróbuj ponownie.");
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
									System.out.println("Wprowadzi³eœ b³êdny znak! Spróbuj ponownie.");
								}
							}
						}
						else if (list.get(7).equals("audiobook")) {
							boolean boo1=true;
							System.out.println("Aktualny format ksi¹¿ki to: "+list.get(8)+". Czy chcesz to edytowaæ? (tak - 1, nie - 2)");
							while(boo1) {
								ch=scanner.next();
								if(ch.equals("1")) {
									System.out.println("Jakiego formatu jest ksi¹¿ka? mp3 - 1, ogg - 2, cd - 3, kaseta - 4, inny - 5");
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
											System.out.println("Wprowadzi³eœ b³êdny znak! Spróbuj ponownie.");
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
									System.out.println("Wprowadzi³eœ b³êdny znak! Spróbuj ponownie.");
								}
							}
						}
						if(!(list.get(7).equals("wersja papierowa"))) {
							listEdit.add(9, list.get(9));
							System.out.println("Ustaw rozmiar ksi¹¿ki:");
							listEdit.add(10, s.nextLine());
						}
						boo=false;
					}
					else {
						System.out.println("Wprowadzi³eœ b³êdny znak! Spróbuj ponownie.");
					}
				}
				t.editRow(ans-1,listEdit);
				System.out.println("Pozycja zosta³a edytowana.");
				read(t);
			}
			else {
				System.out.println("Nie ma pozycji o takim numerze!");
			}
		} catch (InputMismatchException e) {
			System.out.println("Podany znak musi byæ liczb¹ naturaln¹!");
		}
	}
	
	public static void deleteItem(Table t) {
		System.out.println("Któr¹ pozycjê chcesz usun¹æ?");
		read(t);
		try {
			int ans=scanner.nextInt();
			if ((ans<=t.getRowsNum()) && (ans>0)) {
				t.deleteRow(ans-1);
				System.out.println("Pozycja zosta³a usuniêta z bazy.");
				read(t);
			}
			else {
				System.out.println("Nie ma pozycji o takim numerze!");
			}
		} catch (InputMismatchException e) {
			System.out.println("Podany znak musi byæ liczb¹ naturaln¹!");
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
		System.out.println("Czytane ksi¹¿ki: "+stats(listOfLists,0,"W TRAKCIE CZYTANIA")+".");
		System.out.println("Przeczytane ksi¹¿ki: "+stats(listOfLists,0,"PRZECZYTANE")+".");
		System.out.println("Nieprzeczytane ksi¹¿ki: "+stats(listOfLists,0,"NIEPRZECZYTANE")+".");
		System.out.println("Ksi¹¿ki do kupienia: "+stats(listOfLists,0,"DO KUPIENIA")+".");
		System.out.println();
		System.out.println("Ksi¹¿ki w wersji papierowej: "+stats(listOfLists,7,"wersja papierowa")+".");
		System.out.println("E-booki: "+stats(listOfLists,7,"e-book")+".");
		System.out.println("Audiobooki: "+stats(listOfLists,7,"audiobook")+".");
		System.out.println();
		System.out.println("Ksi¹¿ek razem: "+n+".");
	}
	
	/* Main function */
	public static void main(String[] args) {
		System.out.println("Witaj w programie Baza ksi¹¿ek!");
		info();
		boolean x=true;
		while (x) {
			String answer=scanner.next();
			Table t=new Table("baza.txt");
			if (answer.equals("1")) {
				System.out.println();
				read(t);
				System.out.println();
				System.out.println("Jeœli chcesz dzia³aæ dalej wciœnij 0 a nastêpnie ENTER, w przeciwnym wypadku wpisz dowolny klawisz i ENTER.");
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
				System.out.println("Dodano pozycjê do bazy.");
				read(t);
				System.out.println();
				System.out.println("Jeœli chcesz dzia³aæ dalej wciœnij 0 a nastêpnie ENTER, w przeciwnym wypadku wpisz dowolny klawisz i ENTER.");
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
				System.out.println("Jeœli chcesz dzia³aæ dalej wciœnij 0 a nastêpnie ENTER, w przeciwnym wypadku wpisz dowolny klawisz i ENTER.");
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
				System.out.println("Jeœli chcesz dzia³aæ dalej wciœnij 0 a nastêpnie ENTER, w przeciwnym wypadku wpisz dowolny klawisz i ENTER.");
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
				System.out.println("Jeœli chcesz dzia³aæ dalej wciœnij 0 a nastêpnie ENTER, w przeciwnym wypadku wpisz dowolny klawisz i ENTER.");
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
				System.out.println("Wpisa³eœ b³êdny znak! Spróbuj ponownie.");
			}
		}
		scanner.close();
		s.close();
	}
}