#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

//Struct data orang
struct dataOrang {
    char nama[50];
    int umur;
    char npm[15];
    int statusCovid;
    int lokasi[5];
};

//Function prototype
int inputData(struct dataOrang *data,int);
int menu();
void lihatData(struct dataOrang *listdata, int);
void infoCovid(struct dataOrang *listCovid, int);
void updateData(struct dataOrang *updatedata, int);
void bukuPanduan();
void animasiOpening();

//Main Function
int main(){
    menu();
    system("pause");
}

//Function menu utama
int menu(){
    int pilihan = 0, sentinelMenu = 0, i = 0, sentinelInput = 0;
    struct dataOrang *mahasiswa;
    
    mahasiswa = (struct dataOrang*)malloc(i+1 * sizeof(struct dataOrang));
    system ("CLS");
    
    if (mahasiswa == NULL) /* Memory allocation fails */
    {
        printf("\nCouldn't allocate memory");
        exit(1);
    }
    else  /* Memory allocation successful */
    {
        printf("\nMemory allocation successful");
    }
    Sleep(1000);
    system ("CLS");
    
    animasiOpening();
	
	do{
		system ("CLS");
        printf("===================================\n");
        printf("Selamat datang di aplikasi COVID UI\n===================================\n1. Input data\n");
        printf("2. Update data\n3. Lihat data\n4. Info COVID\n5. Panduan\n6. Exit\n===================================\nMasukkan pilihan: ");
        scanf("%d", &pilihan);

        switch(pilihan){
            case 1:
                do{
                system ("CLS");
                inputData(mahasiswa, i);
                i++;

                printf("\n1. Lanjut input data\n2. Keluar\nPilihan: ");
                scanf("%d", &sentinelInput);
                system ("CLS");

                }while(sentinelInput != 2);

                printf("\nTerima kasih atas data yang sudah anda berikan!");
                Sleep(1000);
                system ("CLS");
                break;
                
            case 2:
            	system ("CLS");
                updateData(mahasiswa,i);
                break;

            case 3: 
                system ("CLS");
                lihatData(mahasiswa,i);
                break;
            
            case 4:
                system("CLS"); 
                infoCovid(mahasiswa,i);
                break;
            
            case 5:
            	system ("CLS");
                bukuPanduan();
            	break;
                
            case 6:
            	system ("CLS");
            	free(mahasiswa);
            	printf("\nTerima kasih sudah menggunakan aplikasi ini!");
            	exit(0);
                
            default:
            	printf("\nPilihan tidak ditemukan, ulangi");
            	Sleep(1000);
            	system ("CLS");
            	break;
        }
    }while(sentinelMenu != 2);
 
    printf("\nTerima kasih sudah menggunakan aplikasi!");
    Sleep(1000);
    system ("CLS");
}

//Function Input Data
int inputData(struct dataOrang *data, int i){
    int x;
        printf("\nMasukkan Nama anda, sesuai dengan SIAK: ");
        scanf(" %[^\n]", data[i].nama);
        printf("\nMasukkan umur anda: ");
        scanf("%d", &data[i].umur);
        printf("\nMasukkan NPM anda: ");
        scanf(" %[^\n]", data[i].npm);
        printf("\nApakah anda terkena COVID?\n1. Ya\n2. Tidak\nPilihan: ");
        scanf("%d", &data[i].statusCovid);
            if(data[i].statusCovid == 1){
            	system("CLS");
                printf("\n\nDaftar Lokasi di Universitas Indonesia\n");
                printf("1. Masjid UI\n2. Fakultas Teknik\n3. Fakultas Ekonomi dan Bisnis\n4. Fakultas Farmasi\n5. Fakultas Ilmu Keperawatan\n6. Fakultas Kedokteran\n");
                printf("7. Fakultas Kesehatan Masyarakat\n8. Fakultas Hukum\n9. Fakultas Ilmu Administrasi\n10. Fakultas Ilmu Komputer\n11. Fakultas Ilmu Pengetahuan Budaya\n");
                printf("12. Fakultas MIPA\n13. Fakultas Ilmu Sosial dan Politik\n14. Fakultas Pendidikan Vokasi\n15. Fakultas Psikologi\n16. Fakultas Kedokteran Gigi\n");
                printf("17. Perpustakaan UI\n18. Stadion UI\n19. Stasiun UI\n20. Pusat Kegiatan Mahasiswa");
                printf("\nSilahkan Pilih Tempat Tempat UI di Atas yang Terakhir Anda Kunjungi");
                printf("\nInput Nama Tempat Berdasarkan Angka Diatas dan Input 0 Untuk Selesai(Maksimal 5)\n");
                for(x = 0;x < 5;x++){
                    scanf("%d", &data[i].lokasi[x]);
                }
            }  
}

//function Update Data
void updateData(struct dataOrang *updatedata, int q){
    int pilihanData, sentinel = 0;
    lihatData(updatedata, q);
    printf("Silahkan pilih data yang ingin diubah berdasarkan nomornya\n");
    scanf("%d", &pilihanData);
    system("CLS");
    inputData(updatedata, pilihanData-1);
    system ("CLS");
}

//function Lihat Data
void lihatData(struct dataOrang *listdata, int i){
    int x;
    printf("\n======== Data pasien COVID-19 =========\n");
    for(x = 0; x < i; x++){
		printf("\n\tData ke-%d\n", x + 1);
    	printf("\nNama : %s", listdata[x].nama);
    	printf("\nUmur : %d", listdata[x].umur);
    	printf("\nNPM : %s", listdata[x].npm);
    	printf("\nStatus : ");
    	switch(listdata[x].statusCovid){
	        case 1 :
	            printf("Positif");
	            break;
	        case 2 :
	            printf("Negatif");
	            break;
	       }
       printf("\n\n=======================================\n");
    }
    system ("pause");
}

//Function Info Covid
void infoCovid(struct dataOrang *listCovid, int i){
    int x,y;
    int zona[20] = {0};
    const char *namaTempat[] = {"1.  Masjid UI\t\t\t","2.  Fakultas Teknik\t\t","3.  Fakultas Ekonomi dan Bisnis\t","4.  Fakultas Farmasi\t\t","5.  Fakultas Ilmu Keperawatan\t","6.  Fakultas Kedokteran\t\t",
                "7.  Fakultas Kesehatan Masyarakat","8.  Fakultas Hukum\t\t","9.  Fakultas Ilmu Administrasi\t","10. Fakultas Ilmu Komputer\t","11. Fakultas Ilmu Pengetahuan Budaya",
                "12. Fakultas MIPA\t\t","13. Fakultas Ilmu Sosial dan Politik","14. Fakultas Pendidikan Vokasi\t","15. Fakultas Psikologi\t\t","16. Fakultas Kedokteran Gigi\t",
                "17. Perpustakaan UI\t\t","18. Stadion UI\t\t\t","19. Stasiun UI\t\t\t","20. Pusat Kegiatan Mahasiswa\t"};
    for(x = 0;x < i;x++){
        for(y = 0; y < 5; y++){
            zona[listCovid[x].lokasi[y] - 1]++;
        }
    }
    
    for(x = 0;x < 20; x++){
        printf("\n%s\t", namaTempat[x]);
        switch(zona[x]){
            case 0 ... 10 :
                printf("(Hijau)");
                break;
            case 11 ... 20 :
                printf("(Kuning)");
                break;
            case 21 ... 30 :
                printf("(Merah)");      
                break; 
            default:
                printf("(Hitam)");
                break;
        }
    }
    printf("\n");
    system ("pause");
}

//Function Buku Panduan
void bukuPanduan(){
	int buku = 0;
	printf("Panduan menggunakan aplikasi\n1. Bagaimana cara menggunakan input Data\n2. Bagaimana cara menggunakan update data\n");
	printf("3. Bagaimana cara menggunakan lihat data\n4. Bagaimana cara menggunakan info COVID\n5. Cara exit aplikasi\nPilihan: ");
	scanf("%d", &buku);
	switch(buku){
		case 1:
			system ("CLS");
			printf("\nMasukkan pilihan 1 pada saat di menu, lalu masukkan data diri anda.\n");
			system ("pause");
			break;
		case 2:
			system ("CLS");
			printf("\nMasukkan pilihan 2 pada saat di menu, lalu pilih nomor data yang ingin diubah\n lalu input data dari awal.\n");
			system ("pause");
			break;
		case 3:
			system ("CLS");
			printf("\nDalam pilihan menu ini, akan ditampilkan list dari semua data yang sudah di-input.\n");
			system ("pause");
			break;
		case 4:
			system ("CLS");
			printf("\nDalam pilihan menu ini, akan ditampilkan lokasi yang ada di UI dan akan di tentukan daerah mana\nyang terjangkit virus COVID dengan tipe warna.\n\nHijau adalah 0 ~ 10\nKuning adalah 11 ~ 20\nMerah adalah 21 ~ 30\nHitam yang lebih dari 31\n");
			system ("pause");
			break;
		case 5:
			system ("CLS");
			printf("\nMasukkan pilihan 6 pada saat di menu dan aplikasi akan exit.\n");
			system ("pause");
			break;
		default:
			system ("CLS");
            printf("\nPilihan tidak ditemukan, ulangi\n");
            system ("pause");
            break;
	}
}

//Function Animasi Opening
void animasiOpening(){
	system("CLS");
    printf("======================================================\n");
    Sleep(500);
    printf("||      Selamat Datang di Aplikasi Covid - 19       ||\n");
    Sleep(500);
    printf("||                    Author :                      ||\n");
    Sleep(500);
    printf("||                Kelompok Anggur                   ||\n");
    Sleep(500);
    printf("======================================================\n");
    Sleep(3000);
}
