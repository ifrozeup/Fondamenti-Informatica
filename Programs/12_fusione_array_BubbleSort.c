/*
Scrivere un programma che:
– chiede due volte all'utente di inserire N valori interi, e li salva in due array di
dimensione N;
– ordina quindi ciascun array utilizzando il metodo Bubble Sort;
– effettua la fusione dei due array, in modo che l'array risultante mantenga
l'ordinamento;
– stampa il vettore dopo la fusione.
L'algoritmo Bubble Sort confronta ogni coppia di elementi adiacenti del vettore. Se due
elementi sono nell'ordine sbagliato, essi vengono invertiti (swap). Come risultato, a ogni
passo l'elemento piu grande non ancora ordinato si sposta verso la posizione piu alta
dell'array. Al passo p, gli ultimi p-1 elementi dell'array saranno nella loro posizione
definitiva (non è necessario controllarli di nuovo). L'algoritmo continua a scorrere tutta la
lista finche non vengono piu eseguiti scambi, situazione che indica che la lista è ordinata.
Implementare l'algoritmo scomponendo il problema in sottoproblemi mediante l'uso di
funzioni. Creare una funzione per eseguire l'ordinamento bubblesort di un vettore, una
funzione per eseguire lo swap di due elementi, e una funzione per fondere due array in un
unico vettore.
Valutare inoltre la complessità dell'algoritmo di ordinamento contando il numero totale di
confronti e il numero totale di swap eseguiti e stampare questi valori.
*/
