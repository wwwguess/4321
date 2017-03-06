// Room: /d/hhu/hhu2road1.c

inherit ROOM;
string call_mouse();

void create()
{
	set("short", "林荫道");
	set("long", @LONG
你现在走在河海大学校内的林荫道上
    东北方向堆着一些建筑材料（material）。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "southwest" : __DIR__"hhucross",
]));
	set("no_clean_up", 0);
        set("item_desc",([
            "material" : (: call_mouse :),
        ]));

	setup();
}
string call_mouse()
{
       call_out("find_mouse",10);
       return "你掀开建筑材料，什么也没有发现！\n";
}
void find_mouse()
{
      string fileofmouse=__DIR__"npc/rat.c";
      object ob;
      tell_room(__FILE__,"突然你听到建筑材料中有动静，噌  地蹿出一只老鼠来.\n");
      ob=new(fileofmouse);
      ob->move(__FILE__);
      return;
}
