// Room: /d/snow/inn_3f.c

#include <room.h>
#include <login.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "�����ջ��¥");
	set("long", @LONG
�����������������ջ����¥������������������ס�ĵط���ÿ�춼�������
������һ����������ĵķ�ɣ�ǽ����һ����������è�ı�ī��

           �������־��£��ջ��ף����̷׷ɡ�
               б���⣬��ѻ���㣬��ˮ�ƹ´塣
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
	//	"west" : __DIR__"w_room",
	//	"north" : __DIR__"n_room",
		"down" :"/d/snow/inn_2f",
	//	"east" : __DIR__"e_room",
	]));
	
	set("objects", ([
		"/obj/sbaa/mengzhu":	1,
		]));

	//create_door("north", "����", "south", DOOR_CLOSED);
//	create_door("east", "����", "west", DOOR_CLOSED);
	//create_door("west", "����", "east", DOOR_CLOSED);

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
       printf("%2d %20s %10s %10s \n",i+1,(string)gaoshou_title,(string)gaoshou_name,(string)gaoshou_id);

              }

return 1;
      
              }

