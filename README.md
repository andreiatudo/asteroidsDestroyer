<!--[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/O6DR07p0)
-->

# Minare de resurse de la asteroizi

### Atudosiei Andrei Cristian 322AB

### Sistemul de operare si IDE-ul

- **Windows 11**
- **Visual Studio 2022**

## Descriere generală

În funcția `main` doar am declarat vectorii, am apelat funcțiile care creează vectorii cu ajutorul fișierelor și am apelat funcția care creează fișierele finale.

---

## Structura claselor

### **Asteroid**

- **Descriere:** Inițial voiam să pun automat ID-ul asteroidului, dar am observat că în fișierul de citire poate apărea același asteroid de mai multe ori.
- **Atribute:**
  - `id`
  - `denumirea resursei`
  - `cantitatea totală`
  - `randamentul extracției`
  - `distanța`
- **Functii membre:**
  - Constructori
  - Destructor
  - Operator de afișare
  - Operator de atribuire
  - Get-eri și set-eri

### **Piață**

- **Atribute:**
  - `denumirea resursei`
  - `cantitatea de resurse vândută`
  - `prețul minim`
  - `prețul maxim` (acesta este prețul curent)
  - `prețul actual` (care este de fapt prețul inițial)
- **Funcții membre:**
  - Constructori
  - Destructor
  - Operator de atribuire
  - Operator de afișare
  - Get-eri și set-eri

### **Rachetă**

- **Atribute:**
  - `capacitatea`
  - `consumul combustibilului`
  - `combustibilul disponibil`
  - `prețul`
  - `id-ul rachetei`
  - `static int` care va fi valoarea ID-ului
- **Funcționalități:**
  - Constructori
  - Destructor
  - Operator de atribuire
  - Operator de afișare
  - Get-eri și set-eri

### **Misiune**

- **Atribute:** Similar celorlalte clase, cu informațiile care apăreau în exemplul de pe OCW.
- **Funcții membre:** Funcțiile membre necesare.

> Operatorii de afișare m-au ajutat pentru debugging, pentru a observa dacă se citesc obiectele corespunzător din fișierele de input.

---

## FunctionsHelper

### **citireAsteroizi**

- Citirea primei linii cu titlurile.
- Citirea linie cu linie, separarea pe baza separatorului `;`.
- Utilizare funcții:
  - `linie.find` găsește prima poziție a separatorului `;` și continuă cât timp există separatorul.
  - `substr` oferă un subsir.
  - `stoi` transformă un string în int.
  - `linie.erase(0, poz+1)` șterge caracterele de la început și șterge numărul de caractere precizat
- Crearea obiectului și adăugarea în vector.

### **citireRachete** și **citirePiata**

- Structură similară cu `citireAsteroizi`.
- Informațiile respectă exemplul de pe OCW.

### **calculareKgTotalePerAsteroid**

- Calculează cantitatea totală extrasă de pe asteroid.

### **distantePerAsteroid**

- Calculează distanțele de la fiecare asteroid.

### **creareMisiuni**

- Îmi cer scuze în avans pentru faptul că funcția este atât de lungâ, stiu că aș fi putut să o sparg in mai multe subprograme
- **Vectori utilizați:**
  - Vectorul de misiuni.
  - Vectorul cu kg per asteroid.
  - Vectorul cu ordinea rachetelor.
  - Vectorul cu distanțele per asteroid.
- **Pași:**

  1. Parcurgerea vectorului `kgTotalePerAsteroid`.
  2. Calcularea rachetei cu costul minim, în funcție de numărul de drumuri pe care le-ar face si cat ar costa un drum.
  3. Ajustarea vectorului de kg totale ale asteroidului.
  4. Calcularea costului combustibilului.
  5. Apoi am luat 3 cazuri:

  - Cazul în care capacitatea rachetei e mai mare decât kg de o anumită resursă de pe asteroid și de aici se împarte în 2 cazuri, deoarece vom continua cu resursele de pe asteroidul curent dacă mai sunt și dacă da, verificăm dacă mai încap în rachetă. Dacă nu încap, adăugăm cât mai putem în rachetă și continuăm cu următorul drum. Dacă mai încape tot, adăugăm toată cantitatea din acea resursă (în aceste 2 cazuri se întâmplă adăugarea a două tipuri de resursă în aceeași rachetă).
  - Cazul în care capacitatea rachetei e mai mică decât kg de o anumită resursă de pe asteroid. În acest caz, umplem racheta după care trecem la următoarea din vectorul de ordine.

  6. Calcularea profitului brut în tot acest timp.

### **creareFisiere**

În această funcție ne-am folosit de vectorul de misiuni și vectorul cu piața pentru a crea toate fișierele de afișare conform exemplului de pe OCW.

## Fișier 1: misiuni.csv

Pentru primul fișier de afișare, doar am afișat informațiile din misiune cum se cere (acum am realizat că aș fi putut face asta direct în operatorul de afișare).

## Fișier 2: profit_total.csv

Pentru al doilea fișier m-am folosit de un vector tuple (care conține 3 câmpuri diferite per element). M-am folosit de acesta pentru a afișa profiturile per rachetă și pentru a ține minte în câte misiuni a fost fiecare rachetă.

## Fișier 3: profit_resursa.csv

Pentru al treilea fișier, m-am folosit de faptul că am ținut minte în vectorul cu piața, cantitatea de fiecare resursă vândută și am calculat profitul și am scăzut prețul resursei conform formulei. Dacă cantitatea vândută era mai mică decât pasul pentru împărțirea prețului per kg, înmulțeam doar cantitatea vândută cu prețul actual, dacă nu înmulțeam 10000 cu prețul actual.

## Fișier 4: clasament_rachete.csv

Pentru al patrulea fișier, m-am folosit de același vector tuple de mai sus, pe care l-am sortat în funcție de profitul mediu per misiune de pe rachetă printr-o expresie lambda. Am verificat dacă ambele au cel puțin o misiune realizată și le-am sortat. Dacă nu, am luat doar racheta care avea cel puțin o misiune sau oricare. Apoi am afișat acest vector tuple.
