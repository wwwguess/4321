//road1.c
inherit ROOM;
void create()
{
        set("short", "ɽ��");
        set("long", @LONG
ת��һ��ɽ�꣬���������Բԣ���ɽ��ľ������ɽ�廷�����·�������·��
LONG
        );
        set("exits", ([ 
  "westdown" : __DIR__"road0",
  "northup" : __DIR__"outroom",
]));
        set("outdoors", "tieflag");
        setup();
}
