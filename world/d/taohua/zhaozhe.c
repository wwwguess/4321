// Room: /d/taohua/zhaozhe.c

inherit ROOM;

void create()
{
	set("short", "沼泽");
	set("long", @LONG
这里是肮脏的沼泽，只有蛤蟆的叫声。一片乌黑的
泥潭，你觉有点头晕了，分不清来的路了。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"yinggu",
  "north" : "/d/wudang/tygate2",
  "east"  : __DIR__"zhaozhe",
  "west"  : __DIR__"zhaozhe",
]));                                                  
       set("item_desc", ([
                "蛤蟆": "有一只蛤蟆可以(kill)\n",
                "hama": "有一只蛤蟆可以(kill)\n",
           ]));
	set("no_clean_up", 0);

	setup();
	
}
int valid_leave(object me, string dir)
{          
      int i;
       
        if ((string)this_player()->query("family/family_name")!="桃花岛")
          i = 0;
        else i =20;
          i = (int)this_player()->query_skill("qimen-bagua",1)+i; 
        if (dir=="north"|| dir=="n") 
        { i=i*10-600;
        if (i<=0)
         {
	   this_player()->set_temp("noway");
           return notify_fail("北边被泥潭挡住了去路\n");
          }
         if ((random(i)>8) && !(this_player()->query_temp("noway")))
         { write("你沉思一算,找到了出口\n");
 	   return ::valid_leave(me, dir);
          }
         else
          {this_player()->set_temp("noway");
           return notify_fail("北边是泥潭挡住了去路\n");
          }
         }
         return ::valid_leave(me, dir);
}        


 void init()
{
        add_action("do_kill","kill");
}
int do_kill(string arg)
{ object zhi,me;
  me=this_player(); 
  if (me->query_temp("killed"))
  return notify_fail("没有蛤蟆了。\n");
  
  me->set_temp("killed",1);
  zhi=new(__DIR__"npc/hama");
  zhi->move(environment(me)); 
  zhi->kill_ob(me);
  me->kill_ob(zhi);
  return 1;
