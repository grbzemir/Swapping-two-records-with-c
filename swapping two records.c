#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<stddef.h>


struct Ogrenci
{

     int no;
     char ad[20];
     int ort;



} ;

struct Ogrenci bosOgr = {0,"",0};
struct Ogrenci  ogr = {0,"",0};
struct Ogrenci temp1 = {0,"",0};
struct Ogrenci temp2 = {0,"",0};

FILE *ptr;



void creat()
{    
    system("cls");
    int size;    // size ile boyut alıyoruz ve boyut kadar döngüye sokuyoruz.
    int i;  
    printf("kac ogrenci kaydi yapmak istiyorsunuz: ");


   if((ptr=fopen("yonetimbilisimsistemleri.txt","w"))!=NULL)
   {
      for(i=0;i<size;i++)
      fwrite(&bosOgr,sizeof(struct Ogrenci),1,ptr);

   }

    fclose(ptr);
    printf("%d ogrenci kaydi icin belekte yer ayrildi  \n",size);


}


void ekle()

{   
    system("cls");
    printf("yeni kayit edilecek ogrencinin bilgilerini giriniz: \n");
    printf("ogrenci no: ");
    scanf("%d",&ogr.no);
    printf("ogrenci ad: ");
    scanf("%s",ogr.ad);
    printf("ogrenci ort: ");
    scanf("%d",&ogr.ort);

    if((ptr=fopen("yonetimbilisimsistemleri.txt","r+"))!=NULL)
    {
        fseek(ptr,(ogr.no-1)*sizeof(struct Ogrenci), EEK_SET );
        fwrite(&ogr,sizeof(struct Ogrenci),1,ptr);
    }
    
    fclose(ptr);
    printf("ogrenci kaydi basariyla eklendi... \n");

}

   void sil()
   {
      
       
        system("cls");
        int numara;
        int sonuc;
        sonuc=0;


        printf("silinecek ogrencinin numarasini giriniz: ");
        scanf("%d",&numara);

        if((ptr = fopen("yonetimbilisimsistemleri.txt","r+"))!=NULL)
        {
          
          while(!feof(ptr))

            {

             fread(&ogr,sizeof(struct Ogrenci),1,ptr);
             if(numara== ogr.no)

             {

            fseek(ptr,(ogr.no-1)*sizeof(struct Ogrenci),SEEK_SET);
            fwrite(&bosOgr,sizeof(struct Ogrenci),1,ptr);
            sonuc=1;
            break;

             }

        }
   
    }
        fclose(ptr);
        if(sonuc==0)
        printf(" %d numarali ogrenci kaydi basariyla silindi... \n",numara);
        else        
        printf(" %d numarali ogrenci kaydi bulunamadi... \n",numara);
    

   }


  void yazdir()

  {
      
      system("cls");
      printf("NO\tAd\tOrt\n");
    

        if((ptr = fopen("yonetimbilisimsistemleri.txt","r+"))!=NULL)
        {
          
          while(!feof(ptr))

            {

             fread(&ogr,sizeof(struct Ogrenci),1,ptr);
             printf("%d\t%s\t%d\n",ogr.no,ogr.ad,ogr.ort);


             }

        }

        fclose(ptr);
      

  }


   void yerDegistir()

   {
    
    system("cls");
    int numara1;
    int numara2;

    printf("yer degistrimek istediginiz ogrencilerin numaralarini giriniz: \n");
    printf("1. ogrenci numarasini giriniz: ");
    scanf("%d",&numara1);
    printf("2. ogrenci numarasini giriniz: ");
    scanf("%d",&numara2);

    if((ptr=fopen("yonetimbilisimsistemleri.txt","r+"))!=NULL)
    {
       while (!feof(ptr))
       {
           fread(&temp1,sizeof(struct Ogrenci),1,ptr);
           if(numara1==ogr.no)

           {
              
              temp1.no=ogr.no;
                strcpy(temp1.ad,ogr.ad);
                temp1.ort=ogr.ort;
            
           }

         if (numara2==ogr.no)

         {

            temp2.no=ogr.no;
            strcpy(temp2.ad,ogr.ad);
            temp2.ort=ogr.ort;

         }
    
     }

     fseek(ptr,(numara1-1)*sizeof(struct Ogrenci),SEEK_SET);
     fwrite(&temp2,sizeof(struct Ogrenci),1,ptr);

       
     fseek(ptr,(numara2-1)*sizeof(struct Ogrenci),SEEK_SET);
     fwrite(&temp1,sizeof(struct Ogrenci),1,ptr);

   }

   fclose(ptr);
   printf("%d ve %d numarali ogrencilerin yerleri degistririldi... \n",numara1,numara2);

   }


int main ()

{
     int secim;
     secim=-1;

    while(secim!=0)

    {

    printf("1-Yeni kayit ekleme \n");
    printf("2-kayit silme \n");
    printf("3-kayitlari yazdirma \n");
    printf("4-Yer degistirme \n");
    printf("5-Listele Olustur (resetle) \n");
    printf("6-Cikis \n");
    printf("Seciminiz: ");
    scanf("%d",&secim);

    if(secim==1)
    ekle();

    else if(secim==2)
    sil();

    else if(secim==3)
    yazdir();

    else if(secim==4)
    yerDegistir();

    else if(secim==5)
    creat();

    else if(secim==6)
    printf("cikis yaptiniz... \n");

    else
    printf("hatali secim yaptiniz");

         
    
    }

    return 0;
}