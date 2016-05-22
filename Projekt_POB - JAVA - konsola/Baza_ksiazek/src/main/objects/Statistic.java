package main.objects;

import java.util.List;

public class Statistic {
	
	private int howManyElements;
	private int numberOfColumn;
	private String searchedElement;
	
	public Statistic(int numberOfColumn, String searchedElement) {
		super();
		this.numberOfColumn = numberOfColumn;
		this.searchedElement = searchedElement;
		this.howManyElements=0;
	}
	
	public int howManySearched(List<List<String>> array) {
		int n=array.size();
		String[] Arr = new String[n];
		for (int i=0; i<n; i++) {
			Arr[i] = array.get(i).get(numberOfColumn).toString();
			if (Arr[i].equals(searchedElement)) {
				howManyElements++;
			}
		}
		return howManyElements;
	}
}
