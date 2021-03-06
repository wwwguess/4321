// Room : "/d/jingcheng/baih6.c"
// Made by ysgl (1997.10.23)

#include <ansi.h>
inherit ROOM;

void create()
{
      set("short", HIW"白虎大街"NOR);
	set("long", @LONG
  这里是白虎大街的南段了，北面是白虎大街和朱雀大街的十
字路口，东面传来阵阵丝竹声和欢笑声，那里就是天下闻名
的“长安乐坊",西面是一家水果店, 南面是一个大宅子，据说谁也没见过里面到
底住着什么人，只不过就连京城里最有势力的帮会也不敢到那
儿撒野。
LONG         
	);

	set("exits", ([ 
		"north" :__DIR__"baih5",
		"east" :__DIR__"cayfang",   
		"west" :__DIR__"shuiguod",
	]));    

	set("outdoors", "city");
	setup();
}
                
void init()
{	
	add_action("do_play", "play");
}

int do_play(string arg)
{
	object me, ob, obj, jiaren;
	me = this_object();
	ob = this_player();
                           
	if( !(obj=present("baiyu pipa", ob)) )
		return 0;  
	if( !arg || (arg != "pipa" && arg !="琵琶" && arg != "白玉琵琶") )                   
		return notify_fail("你要弹什么？\n");
	if( ob->query_temp("ask_pipa") ) 
		return notify_fail("放肆，在这儿你弹什么弹？\n");
	if( ob->query_skill("music", 1) < 30 )
		return notify_fail("你的琵琶声真是太难听了，还是赶快打住，别让人轰你走吧。\n");
	jiaren = new(__DIR__"npc/jiaren");
	jiaren->move(me);
	message_vision("只听见朝南的门“吱呀”一声开了，走出一个青衣家人来。\n");
	tell_object(ob,GRN"青衣家人躬身对你说："+RANK_D->query_respect(ob)+
	"真是好技艺，我家主人对此十分佩服\n"
	"特意让我来邀请客人入内一见。\n"NOR);
	ob->set_temp("enter", 1);
	me->set("exits/south", __DIR__"baih7");
	remove_call_out("close");
	call_out("close", 5, me, ob);
	return 1;
}                              

int valid_leave(object ob, string dir)
{
	if( !ob->query_temp("enter") && dir == "south" ) 
		return notify_fail("青衣家人伸手拦住你说：我家主人并未邀请你，客人还是请回吧。\n");
	tell_object(ob,GRN"青衣家人向大院一伸手道：客人这边请。\n"NOR);
	return ::valid_leave(ob, dir);                 
}                                

void close(object me, object ob)
{
	message_vision("指听见“砰”的一声，青衣家人走进大院，把门关上了。\n");
	me->delete("exits/south"); 
	destruct(ob);
}