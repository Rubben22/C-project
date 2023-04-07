TAD-uri implementate (Proprietatile 2-5):
1.Lista simpla inlantuita - am folosit-o pentru a gestiona multimea utilizatorilor retelei
2.Multimap - Cheia este reprezentata de numele si prenumele utilizatorului care se logheaza, iar fiecare cheie contine
detaliile utilizatorului care ii este 'prieten'.


Specificatii proiect:
La pornirea aplicatiei se va deschide o consola cu 3 optiuni:

I. Daca selectezi prima optiune iti vei crea un cont (in caz ca nu ai unul) cu care te vei putea loga mai departe.
- Contul tau va ramane salvat si te vei putea re-autentifica in cont
- De asemenea toate modificarile pe care le faci cat timp esti logat vor ramane salvate.
- Daca incerci sa iti faci cont cu un ID deja existent, programul va arunca o eroare (ID-ul trebuie sa fie unic)
- NU poti sa te loghezi daca nu stii datele de autentificare corect (nume, prenume, parola).

II. A doua optiune este pentru a te loga dupa ce ai deja cont. Pentru a te loga folosesti doar numele, prenumele si parola.
- Dupa ce te loghezi vei avea mai multe optiuni:
  1. - Vei adauga un prieten in lista ta de prieteni
     - Nu poti adauga un prieten care nu este inregistrat! Daca faci asta, programul va arunca o exceptie.
     - Datele se vor salva in fisier cu ajutorul MultiMap-ului in care cheia este numele si prenumele utilizatorlui, iar
       valoarea cheii este utilizatorul pe care il adaugi ca prieten din lista de useri. (bineinteles, nu o sa i se afiseze
       parola respectivului utilizator, chiar daca in fisier este scrisa si parola).

  2. - Poti sterge un prieten din lista ta de prieteni.

  3. - Vezi lista cu toti prietenii tai.
  OBS:Toate modificarile pe care le faci cu privire la prietenii tai vor ramane salvate in fisier!

  4. - Trimiti un mesaj la un utilizator al retelei, nu trebuie neaparat sa faca parte din lista ta de prieteni, este
  suficient sa fie inregistrat in retea.
     - Daca incerci sa trimiti un mesaj unui utilizator care nu e inca inregistrat, programul va arunca o eroare!
     - Daca incerci sa trimiti un mesaj cu un ID existent, programul va arunca eroare (ID-ul trebuie sa fie unic)

  5. - Stergi un mesaj trimis
     - Stergerea se face dupa ID-ul mesajului
     - Daca incerci sa stergi un mesaj dupa un ID inexistent, programul va arunca o eroare

  6. - Afiseaza toate mesajele trimise

  7 - Afiseaza toate mesajele primite

  0 - Logout

III. A treia optiune este logarea ca administrator. Pentru a te loga folosesti userul "admin" si parola "admin10"
De aici ai acces la: - toti utilizatorii retelei pe care ii poti sterge, modifica sau adauga altii noi.
                     - de asemenea poti vizualiza toate mesajele schimbate de utilizatori si le poti sterge,
                       fiind administratorul retelei

OBS: Toate modificarile pe care le faci din postura de administrator (ex. stergere/update/add user/message) vor ramane
salvate si in fisier. Astfel ca, de exemplu daca stergi un utilizator si acesta va incerca sa se autentifice va intampina
erori, doarece contul sau a fost sters de administrator.