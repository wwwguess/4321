// road0.c
inherit ROOM;
void create()
{
        set("short", "ɽ��С·");
        set("long", @LONG
����ɽɫ������������·����������̦޺������������е�����������ɽ�
�ɣ��Ĳ�û����
LONG
        );
        set("exits", ([ 
  "eastup" : __DIR__"road1",
  "westdown" : __DIR__"road",
]));
        set("outdoors", "tieflag");
        setup();
}
void init()
{
	add_action("do_go","go");

}

int do_go()
{
if(random(3)){
this_player()->move(this_object());
return 1;
}
}
