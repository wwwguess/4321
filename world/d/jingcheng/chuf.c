// Room: /d/shaolin/chufang2.c
// Date: YZC 96/01/19

inherit ROOM;




void create()
{
	set("short", "厨房");
	set("long", @LONG
这里是贾家包子铺的厨房。厨房很大，里面凌乱不堪.苍蝇满天飞.
灶头砌在北首，一根大烟囱直通出屋顶。房子四壁被常年烟火熏得
发黑，连房梁也是焦黑焦黑的.灶上锅里还飘着只死老鼠,灶下烧着
火,都煮熟了.   东边的墙灰剥落了一块，露出犬牙交错的砖缝来。
屋角边有个大洞(dong)。
LONG
	); 
        set("objects", ([
                
                __DIR__"obj/rou.c" : 2,     
        ]));


	set("exits", ([
		"south" : __DIR__"jjbz",
	]));

	set("item_desc",([
		"brick"	: "西...东...北...东...南\n",
		"dong"	: "墙角被扒开了个大洞，里面黑沉沉的，不知通往哪里。\n"
	])); 


 }

 void init()
 {
        add_action("do_enter", "enter");
        add_action("do_enter", "zuan");
 }

 int do_enter(string arg)
 {
	object me;
	mapping fam;

	me = this_player();

	if( !arg || arg=="" ) return 0;

	if( arg=="dong" )
	{
		if( (fam = me->query("family")) && fam["family_name"] == "丐帮" ) 
		{
			message("vision",
				me->name() + "运起丐帮缩骨功，一弯腰往洞里钻了进去。\n",
				environment(me), ({me}) );
			me->move("/d/gaibang/jingch");
                	message("vision",
				me->name() + "从洞里走了进来。\n",
                		environment(me), ({me}) );
			return 1;
		}
		else 
			return notify_fail("这么小的洞，你钻得进去吗？\n");
	}
}	



