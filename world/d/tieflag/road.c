// road.c
inherit ROOM;
void create()
{
        set("short", "С·");
        set("long", @LONG
���￿�������ɽǧ�𶴣���������ɽ��ɽ�µıؾ�֮·��
��·����һƬСС���֣�һ��ʯ��������ʯ�ʡ�һ��С��
�ڴ���������������Ϊ��¡��
LONG
        );
        set("exits", ([
  "eastup" : __DIR__"road0",
  "north" : __DIR__"troad4",
]));
        set("objects", ([
               __DIR__"npc/xiaofan" : 1,
       ]) );
        set("outdoors", "tieflag");
        setup();
}
