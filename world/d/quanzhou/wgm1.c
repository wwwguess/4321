// room: wgm1.c
// Jay 9/9/97
//write by lysh
#include <room.h>
#include <ansi.h>

inherit ROOM;
//inherit F_CLEAN_UP;
int destmu();

void create()
{
    set("short", "泉州武馆");
    set("long", @LONG 
    这里是精武武馆泉州分馆，地上横七竖八地放着一些石锁、石鼓，
墙角立着一些木桩，北边是练武厅，厅内隐隐传出打斗声。墙上挂着
一块牌子(paizi)。
LONG
    );
    set("item_desc", ([
		"paizi" : "本武馆暂时关闭 \n"
                        "\n               泉州分馆立\n"
        ]));

    set("exits", ([
//	"north" : __DIR__"wg1",
	"south" : __DIR__"dongjie",
    ])); 
            set("objects",([
//		__DIR__ +"npc/wangerm.c" : 1,
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
  if(objectp(present("wang er ma", environment(me))))
    {  
  if(!present("wang er ma")->query_temp("有人/mark"))
     {
  if( this_player()->query_temp("教钱了/mark"))
      {

     write("王二麻:小的这就把木人准备好，大爷请进。\n");       
     this_player()->delete_temp("教钱了/mark");              
     present("wang er ma")->set_temp("有人/mark",1);
 //    destmu();         
     return ::valid_leave(me, dir);                           
     
      }
  else
  return notify_fail("王二麻一瞪眼，穷鬼，边呆这去 。\n");     
       }
  else
  return notify_fail("王二麻:对不起，有人在练功了。\n");     
    }
  else
    me->move(__DIR__"wgn1");  
    return notify_fail("你向北走去，可是武馆里的木人还没有准备好。\n");
  }
  else
  return ::valid_leave(me,dir);
}
  
int destmu()
{
	int i;
	object *inv;
	inv = all_inventory(find_object(__DIR__"wg1"));
	i = sizeof(inv);
	while(i--)
		if( !userp(inv[i]) ) destruct(inv[i]);
	return 1;
}
