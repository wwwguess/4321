// room: wgm3.c
// Jay 9/9/97
//write by lysh
#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{
    set("short", "练武场");
    set("long", @LONG 
    这里是一个练武场，地上横七竖八地放着一些石锁、石鼓，墙
角立着一些木桩，北边是练武厅，厅内隐隐传出打斗声。墙上挂着
一块牌子(paizi)。
LONG
    );
    set("item_desc", ([
                "paizi" : "来本武场练武需交黄金 5 两。\n"  
                        "\n               神教总管立\n"
        ]));

    set("exits", ([
        "north" : __DIR__"wg3",
	 "west" : __DIR__"dingfeng6",
    ])); 
            set("objects",([
		__DIR__ +"npc/jianqiankai.c" : 1,
            ]));
    set("no_fight",1);
    set("no_steal",1);
    set("no_sleep_room",1);
    setup();
    set("no_clean_up",1);
}
   
int valid_leave(object me,string dir)
{
  if (dir == "north" ) 
  {
  if(objectp(present("jian qian kai", environment(me))))
    {  
  if(!present("jian qian kai")->query_temp("有人/mark"))
     {
  if( this_player()->query_temp("教钱了/mark"))
      {

     write("见钱开:小的这就把木人准备好，大爷请进。\n");       
     this_player()->delete_temp("教钱了/mark");              
     present("jian qian kai")->set_temp("有人/mark",1);  
     return ::valid_leave(me, dir);                           
     
      }
  else
  return notify_fail("见钱开一瞪眼，穷鬼，一边呆这去 。\n");     
       }
  else
  return notify_fail("见钱开:对不起，有人在练功了。\n");     
    }
  else
    me->move(__DIR__"wgn3");  

  }
  else
  return ::valid_leave(me,dir);
}
  
