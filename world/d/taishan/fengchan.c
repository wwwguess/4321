// Room: /d/taishan/fengchan.c

#include <room.h>
#include <login.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "����̨");
	set("long", @LONG
�����������ѡ��������������֮������·Ӣ�����ܼ�ѹȺ�ۣ�
�������������ʶ�������������Ϊͳ����ԭ���ֵ����䡣��̨��
�ڷ��ź����������������ڴ��������¡�̨�ϸ߸�����һ���죬
���飺�����е� �ĸ����֡� ̨������һ�����ĸ�ʾ��(sign)��
�������Ҹ���������λ������ʿ����
�߶�����һ���Ż�Ƥ���Σ�ʱ��������ǰ������ǰ���μ�������
LONG
	);
        set("exits", ([
                "down" : __DIR__"yuhuang",
                "east" : __DIR__"xiayi",
                "west" : __DIR__"zhengqi",
        ]));  

        set("objects",([
         //       "/d/taishan/npc/mengzhu" : 1,
            	"/u/sbaa/mengzhu" : 1,
		   __DIR__"npc/wei-shi1" : 4,
        ]));
        set("item_desc", ([
                "sign": @TEXT
             ��      ʾ
    Ŀǰ�Ӻ�MUD��ʮ����֣�����������
    ������ paiming �鿴��
TEXT
        ]) );       

        set("no_clean_up", 1);
        set("outdoors", "taishan");

	setup();
}
void init()
{ add_action ("do_paiming","paiming");
}
int do_paiming()
{
        string uid, gaoshou_id,gaoshou_name,gaoshou_title;
        string  now_id,now_name,now_title;
        string *gaoshoulist,gaoshoulist2,*gaoshou_status;
        int i,j,gaoshou_exp,now_exp;
         gaoshoulist = explode(read_file(RICHMAN), "\n");
        printf(RED "�Ӻ�mud�е����ʮ��������\n" BLU);
        gaoshou_status = allocate(sizeof(gaoshoulist));
        for(i=0; i<10; i++) {
                if( sscanf(gaoshoulist[i], "%s %s %s %d", gaoshou_id,gaoshou_name,gaoshou_title,gaoshou_exp)!=4 ) continue;
                gaoshou_status[i] = (string)gaoshou_id+" "+
                                 (string)gaoshou_name+" "+
                                 (string)gaoshou_title+" "+
                                 (string)gaoshou_exp;
       printf("%2d %20s %10s %10s \n",i+1,(string)gaoshou_title,(string)gaoshou_name,(string)gaoshou_id);

              }
gaoshoulist = explode(read_file(GAOSHOU), "\n");
        printf(HIY "�Ӻ�mud�е����ʮ���������\n" HIG);
        gaoshou_status = allocate(sizeof(gaoshoulist));
        for(i=0; i<10; i++) {
                if( sscanf(gaoshoulist[i], "%s %s %s %d", gaoshou_id,gaoshou_name,gaoshou_title,gaoshou_exp)!=4 ) continue;
                gaoshou_status[i] = (string)gaoshou_id+" "+
                                 (string)gaoshou_name+" "+
                                 (string)gaoshou_title+" "+
                                 (string)gaoshou_exp;
       printf("%2d %20s %10s %10s \n",i+1, (string)gaoshou_title,(string)gaoshou_name,(string)gaoshou_id);
              }
printf("%s", " \n" NOR);
return 1;
      
              }

