// Room: /d/snow/inn_3f.c

#include <room.h>
#include <login.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "饮风客栈三楼");
	set("long", @LONG
你现在来到了饮风客栈的三楼，这里是武林盟主居住的地方，每天都有许多人
来这里一睹武林至尊的的风采，墙上有一幅画，是老猫的笔墨。

           多少武林旧事，空回首，如烟纷飞。
               斜阳外，寒鸦数点，流水绕孤村。
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

	//create_door("north", "房门", "south", DOOR_CLOSED);
//	create_door("east", "房门", "west", DOOR_CLOSED);
	//create_door("west", "房门", "east", DOOR_CLOSED);

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
        printf(RED "河海mud中当今的十大富人排名\n" BLU);
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
        printf(HIY "河海mud中当今的十大高手排名\n" HIG);
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

