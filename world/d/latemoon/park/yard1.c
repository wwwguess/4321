
inherit ROOM;

void create()
{
    set("short","ǰԺ");
	set("long", @LONG
���ߵ�ǰԺ���㿴������ɽʯ������һ����ɽС�ء�����ֲ����  
�ܡ����ƣ���ݷҷ���Ѧ�����м�βС�����ڵ�������ȥ����ɽ���
��Χ�飬��һ��ɽ���е�С��԰�ĸо���.
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
     "north" : "/d/latemoon/front_yard",
     "south" :__DIR__"flower2",

]));
    set("outdoors", "latemoon");

	setup();
	replace_program(ROOM);
}
