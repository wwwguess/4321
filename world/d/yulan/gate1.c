// Room: /d/maintown/mt_gate1.c

#include <room.h>

inherit ROOM;

string look_bugao(object me);

void create()
{
	set("short", "城门口");
	set("long", @LONG
你的面前就是此行的目的地－－－长沙城，最近一段时间，它成了朝廷和江
湖人士注意的地方。那用糯米青砖砌的城墙，虽然已经有上百年的历史，却
仍然非常坚固，城楼上两个遒劲的大字“长沙”直欲破壁飞去。城门口的高
处用竹竿挑着两个木笼，里面装着前天处死的江洋大盗的人头(head)。
向北就是那厚实的大门(gate)，南方有一条崎岖难行的小路通向远方。
LONG           
);

	set("item_desc", ([
		"gate":"这是一堵厚有三尺的大木门，刚用红漆刷新过，闻上去
还有一股怪味。\n",

		"head":"两个须发披散的人头，面目虽然已开始腐烂，但仍能看
出那股恐惧和愤怒的表情\n",


	]) );

	set("exits", ([ /* sizeof() == 2 */
		  "west" : "/d/yulan/gate2",
		  "east" : "/d/yulan/road",]));


	set("objects", ([
		"/d/maintown/npc/gateman" : 2 ]) );  

        set("no_clean_up", 0);
        set("outdoors", "maintown");

        create_door("west", "长沙城大门", "east", DOOR_CLOSED);
        
	setup();
        replace_program(ROOM);
}

