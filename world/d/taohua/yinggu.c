// Room: /d/taohua/yinggu.c
//write by lysh
inherit ROOM;

void create()
{
	set("short", "瑛姑居");
	set("long", @LONG
这里是瑛姑居所，只见当前一张长桌，上面放这
七盏灯，摆成天罡北斗之形。地面细沙上似乎写着什么。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
 
  "north" : __DIR__"zhaozhe",
       ]));                                                  
       set("item_desc", ([
                "ground": "今有物不知其数，三三数之剩二，五五之数之剩三，七七之数之剩二，问物几何？(think)\n",
                "地面": "今有物不知其数，三三数之剩二，五五之数之剩三，七七之数之剩二，问物几何？(think)\n",
           ]));
	set("no_clean_up", 0);

	setup();
	
}


 void init()
{
        add_action("do_think","think");
}
int do_think(string arg)
{ object me;
  int i;
  me=this_player(); 
  i=(int)me->query_skill("qimen-bagua",1);
  if (i<68) return notify_fail("你左思右想，怎么也想不出来。\n");
  if (i>=68 && i<71) {i=i+1;
                      me->set_skill("qimen-bagua",i);
                      return notify_fail("你左思右想,心中突然一动，有了答案。\n");
                      }
  if (i>70) return notify_fail("这题太简单了。\n");
  return 1;
