package main.objects;

public class Ebook extends Book {

	private String format;
	private String size;
	
	public Ebook() {
		super();
	}
	
	public String getFormat() {
		return format;
	}
	
	public void setFormat(String format) {
		this.format = format;
	}
	
	public String getSize() {
		return size;
	}
	
	public void setSize(String size) {
		this.size = size;
	}
	
	public String getCover() {
		return "nie dotyczy";
	}
	
	public String getClassType() {
		return "e-book";
	}
	
	@Override
	public void setCover(String cover) {}

}
