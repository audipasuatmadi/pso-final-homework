#include <stdio.h>
#include <stdlib.h>

// Contoh ILUSTRASI program yang mengurus UI thread dan juga memanggil Database Thread
// Jangan sampai UI Thread terblock karena memanggil database thread, akan membuat UI freeze untuk users di studi kasus nyata.

void printlnKeyValue(char key[], char value[])
{
  printf("[%s]: %s\n", key, value);
}

void callDatabase()
{
  printlnKeyValue("CALL DATABASE FUNC", "starting function");
  printlnKeyValue("CALL DATABASE FUNC", "calling database on IP Address: X");
  sleep(2);
  printlnKeyValue("CALL DATABASE FUNC", "database not found, calling to another database shard on IP Address: X");
  sleep(5);
  printlnKeyValue("CALL DATABASE FUNC", "database found, retrieving data");
  sleep(1);
}

void showUI()
{
  int exampleUiThreadInput;
  printlnKeyValue("UI THREAD", "Showing user interface to users...");
  printf("Masukkan pilihan menu (cotoh, masukkan angka apa saja boleh): ");
  scanf("%d", &exampleUiThreadInput);
}

int main()
{
  printlnKeyValue("MAIN FUNC", "starting main function");
  printlnKeyValue("MAIN FUNC", "starting to call database");

  // Panggilah fungsi ini pada thread lain agar tidak menyebabkan Blocking terhadap fungsi UI di bawah
  callDatabase();

  showUI();
  return 0;
}