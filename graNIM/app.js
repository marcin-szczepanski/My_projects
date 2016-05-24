document.getElementById("okno_info").style.display = "none";
document.getElementById("okno_podsumowania").style.display = "none";
document.getElementById("ostatni_ruch").style.visibility = "hidden";
var poleIleZetonow=document.getElementById("ileZetonow"); 
poleIleZetonow.value="";
var buttonOK=document.getElementById("ok");
var buttonOK1=document.getElementById("ok1");
var buttonWez1=document.getElementById("1_zeton");
var buttonWez2=document.getElementById("2_zeton");
var liczba_zetonow=0;
var ktoGra="Komputer";
var wygral="Komputer";
var ktoWygral=document.getElementById("kto_wygral");
var kto="Użytkownik";
var ile=0;

function refresh()
{
	document.getElementById("ile_zetonow").innerHTML=liczba_zetonow;
}

function ileWziacZetonowKomputer()
{
	if (liczba_zetonow==0)
	{
		koniecGry();
	}
	else
	{
		if ((liczba_zetonow/3)==Math.ceil(liczba_zetonow/3))
		{
			liczba_zetonow=liczba_zetonow-2;
			ile=2;
		}
		else
		{
			liczba_zetonow=liczba_zetonow-1;
			ile=1;
		}
		zmianaUzytkownika();
		refreshOstatniRuch();
	}
	
}

function wezJedenZeton()
{
	liczba_zetonow=liczba_zetonow-1;
	ile=1;
	zmianaUzytkownika();
	refreshOstatniRuch();
}

function wezDwaZetony()
{
	if(liczba_zetonow==1)
	{
		alert("Nie możesz wziąć dwóch żetonów!");
	}
	else
	{
		liczba_zetonow=liczba_zetonow-2;
		ile=2;
		zmianaUzytkownika();
		refreshOstatniRuch();
	}
}

function ruch() 
{
	if (liczba_zetonow==0)
	{
		koniecGry();
	}
	else
	{
		buttonWez1.disabled=false;
		buttonWez2.disabled=false;
	}
}

function refreshOstatniRuch()
{
	if (kto=="Użytkownik")
	{
		kto=kto+"a";
	}
	document.getElementById("kto").innerHTML=kto;
	document.getElementById("ile").innerHTML=ile;
	document.getElementById("ostatni_ruch").style.visibility = "visible";
}

function zmianaUzytkownika()
{
	refresh();
	kto=ktoGra;
	if (liczba_zetonow!=0)
	{
		if (ktoGra=="Komputer")
		{
			ktoGra="Użytkownik";
			document.getElementById("ktoGra").innerHTML=ktoGra;
			ruch();
			refresh();
		}
		else
		{	buttonWez1.disabled=true;
			buttonWez2.disabled=true;
			ktoGra="Komputer";
			document.getElementById("ktoGra").innerHTML=ktoGra;
			window.setTimeout(ileWziacZetonowKomputer, 3000);
		}
	}
	else
	{
		koniecGry();
	}
}

function uruchom()
{
	document.getElementById("ostatni_ruch").style.visibility = "hidden";
	liczba_zetonow=poleIleZetonow.value;
	if((isNaN(liczba_zetonow)) || (liczba_zetonow.length==0) || (liczba_zetonow<0) || (liczba_zetonow!=Math.ceil(liczba_zetonow)))
	{ 
		alert('Podaj dodatnią liczbę naturalną!');
	}
	else if ((liczba_zetonow<=2))
	{
		alert('Gramy na co najmniej 3 żetonach!');
	}
	else
	{
		document.getElementById("okno_podsumowania").style.display = "none";
		liczba_zetonow.value
		poleIleZetonow.value="";
		document.getElementById("okno_info").style.display = "block";
		document.getElementById("okno_powitalne").style.display = "none";
		refresh();
		zmianaUzytkownika();
	}
}

function keyDown(event) 
{
	event.which = event.which || event.keyCode;
	if (event.which==13) 
	{
		uruchom(); 
	}
}

function ktoWygralGre()
{
	if(ktoGra=="Komputer")
	{
		return "Użytkownik";
	}
	else
	{
		return "Komputer";
	}
}

function koniecGry()
{
	refreshOstatniRuch();
	buttonWez1.disabled=true;
	buttonWez2.disabled=true;
	document.getElementById("okno_podsumowania").style.display = "block";
	wygral=ktoWygralGre();
	ktoWygral.innerHTML=wygral;
	poleIleZetonow=document.getElementById("ileZetonow1"); 
	poleIleZetonow.value="";
}

buttonOK.onclick = uruchom;
buttonOK1.onclick = uruchom;
document.onkeydown=keyDown;
buttonWez1.onclick=wezJedenZeton;
buttonWez2.onclick=wezDwaZetony;