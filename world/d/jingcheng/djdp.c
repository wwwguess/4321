// Room: /d/jingcheng/djdp.c
// Made by: ysgl

#include <ansi.h>
inherit HOCKSHOP;

void create()
{
	set("short", "[1;37m���ǵ���[2;37;0m");
	set("long", @LONG
���ǳ�����������һ�ҵ����ˡ�������������ƽ�ųơ��ſڹ���һ����
�ӣ����ϰ��Ǹ��ܾ����������ˣ��������˽������ܿ����غ���
���ѣ����۾���ȴû��ʲôЦ�⣬�������ش������㡣
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"ndj1",
]));
        set("objects", ([
        __DIR__"npc/dong.c" : 1,
]));                
//    set("dangpu_location","yangzhou");
	setup();
}
