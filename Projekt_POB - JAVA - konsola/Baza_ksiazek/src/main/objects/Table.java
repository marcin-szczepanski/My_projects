package main.objects;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.PrintWriter;
import java.nio.file.Files;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;
import java.util.NoSuchElementException;
import java.util.Scanner;

public class Table {
	
	private File mFile;
	
	public Table(String file) {
		mFile=new File(file);
		try {
			if (mFile.exists()==false) {
				mFile.createNewFile();
			}
		} catch (IOException e) {
			System.out.println("B³¹d przy tworzeniu pliku!");
		}
	}
	
	public List<String> getRow(int n) {
		String row;
		Scanner read;
		try {
			read = new Scanner(mFile);
			row=read.nextLine();
			for (int i=1; i<=n; i++) {
				row=read.nextLine();
			}
			row=row.substring(0, row.length());
			
			List<String> list = new ArrayList<String>(Arrays.asList(row.split(";")));
			read.close();
			return list;
		} catch (FileNotFoundException e) {
			List<String> list=Collections.emptyList();
			System.out.println("Nie znaleziono pliku z baz¹ ksi¹¿ek!");
			return list;
		}
	}
	
	public int getRowsNum() {
		Scanner read;
		int i=0;
		try {
			read=new Scanner(mFile);
			while (read.hasNextLine()) {
				read.nextLine();
				i++;
			}
			read.close();
		} catch (FileNotFoundException e) {
			System.out.println("Nie znaleziono pliku z baz¹ ksi¹¿ek!");
			return 0;
		} catch (NoSuchElementException e) {}
	    return i;
	}
	
	public void deleteRow(int n) {
		File tmp=new File("tmp"+mFile.getName());
		PrintWriter saving;
		try {
			saving = new PrintWriter(tmp);
			for (int i=0; i<this.getRowsNum(); i++) {
		        if (i == n) {
		        	continue;
		        }
		        String row=String.join(";",this.getRow(i));
		        
		        saving.println(row);
			}    
			saving.close();
		    mFile.delete();
		    File newFile = new File(tmp.getParent(), mFile.getName());
		    try {
				Files.move(tmp.toPath(), newFile.toPath());
			} catch (IOException e) {
				System.out.println("B³¹d przy usuwaniu!");
			}
		} catch (FileNotFoundException e) {
			System.out.println("Nie znaleziono pliku z baz¹ ksi¹¿ek!");
		}
	}
	
	public void insertRow(List<String> values){
		File tmp=new File("tmp"+mFile.getName());
		PrintWriter saving;
		String row;
		try {
			saving = new PrintWriter(tmp);
			for (int i=0; i<this.getRowsNum()+1; i++) {
				if (i == this.getRowsNum()) {
					row=String.join(";",values);
				}
				else {
					row=String.join(";",this.getRow(i));
				}
							
				saving.println(row);
			}    
			saving.close();
		    mFile.delete();
		    File newFile = new File(tmp.getParent(), mFile.getName());
		    try {
				Files.move(tmp.toPath(), newFile.toPath());
			} catch (IOException e) {
				System.out.println("B³¹d przy dodawaniu!");
			}
		} catch (FileNotFoundException e) {
			System.out.println("Nie znaleziono pliku z baz¹ ksi¹¿ek!");
		}
	}
	
	public void editRow(int n, List<String> values) {
		File tmp=new File("tmp"+mFile.getName());
		PrintWriter saving;
		String row;
		try {
			saving = new PrintWriter(tmp);
			for (int i=0; i<this.getRowsNum(); i++) {
				if (i == n) {
					row=String.join(";",values);
				}
				else {
					row=String.join(";",this.getRow(i));
				}
							
				saving.println(row);
			}    
			saving.close();
		    mFile.delete();
		    File newFile = new File(tmp.getParent(), mFile.getName());
		    try {
				Files.move(tmp.toPath(), newFile.toPath());
			} catch (IOException e) {
				System.out.println("B³¹d przy dodawaniu!");
			}
		} catch (FileNotFoundException e) {
			System.out.println("Nie znaleziono pliku z baz¹ ksi¹¿ek!");
		}
	}
	
}