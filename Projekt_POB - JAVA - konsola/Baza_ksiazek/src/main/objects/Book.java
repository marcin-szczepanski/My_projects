package main.objects;

public abstract class Book {
	
	private String title;
	private String author;
	private String dateOfPublication;
	private String publication;
	private String genre;
	private String state;
	private String numberOfPages;
	
	public Book() {
		super();
	}
	
	public String getTitle() {
		return title;
	}
	
	public void setTitle(String title) {
		this.title = title;
	}
	
	public String getAuthor() {
		return author;
	}
	
	public void setAuthor(String author) {
		this.author = author;
	}
	
	public String getDateOfPublication() {
		return dateOfPublication;
	}
	
	public void setDateOfPublication(String dateOfPublication) {
		this.dateOfPublication = dateOfPublication;
	}
	
	public String getPublication() {
		return publication;
	}
	
	public void setPublication(String publication) {
		this.publication = publication;
	}
	
	public String getGenre() {
		return genre;
	}
	
	public void setGenre(String genre) {
		this.genre = genre;
	}
	
	public String getState() {
		return state;
	}
	
	public void setState(String state) {
		this.state = state;
	}
	
	public String getNumberOfPages() {
		return numberOfPages;
	}
	public void setNumberOfPages(String numberOfPages) {
		this.numberOfPages = numberOfPages;
	}
	
	public abstract String getFormat();
	public abstract String getCover();
	public abstract void setCover(String cover);
	public abstract String getClassType();
	public abstract void setSize(String size);
	public abstract String getSize();
	public abstract void setFormat(String format);
}
