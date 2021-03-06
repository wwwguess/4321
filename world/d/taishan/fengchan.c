// Room: /d/taishan/fengchan.c

#include <room.h>
#include <login.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "封禅台");
	set("long", @LONG
如今这里是推选天下武林总盟主之处，各路英雄如能技压群雄，
比武夺魁，便能问鼎盟主宝座，成为统领中原武林的领袖。高台上
摆放着汉白玉宝座，盟主便在此坐堂议事。台上高高立着一竿旗，
上书：替天行道 四个大字。 台子左面一个大大的告示牌(sign)，
盟主左右各侍立着四位白衣武士，两
边都放着一长排虎皮交椅，时常有武林前辈高手前来参见盟主。
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
             告      示
    目前河海MUD的十大高手，富翁排名榜
    可以用 paiming 查看！
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
       printf("%2d %20s %10s %10s \n",i+1, (string)gaoshou_title,(string)gaoshou_name,(string)gaoshou_id);
              }
printf("%s", " \n" NOR);
return 1;
      
              }

