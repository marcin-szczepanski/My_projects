package main.objects;

public class Paper extends Book {

	private String format;
    private String cover;
    
	public Paper() {
		super();
	}

	public String getFormat() {
		return format;
	}

	public void setFormat(String format) {
		this.format = format;
	}

	public String getCover() {
		return cover;
	}

	public void setCover(String cover) {
		this.cover = cover;
	}
    
	public String getClassType() {
		return "wersja papierowa";
	}
	
	public String getSize() {
		return "nie dotyczy";
	}

	@Override
	public void setSize(String size) {}
	
}
