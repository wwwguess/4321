
inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
ʯ���ĳ�ԫ�᲼�ڲ���������ǡ�˲���ɽ֮�䡣������һ���������¡�
�������������ɮ�ķ�Ǻ��������������Ĵ�˵���񻰡��������˵Ĺ���
��Ȼ�����������ǰ��
LONG
        );
        set("exits", ([ 
  "west" : __DIR__"octostreet",
  "east" : __DIR__"grassland4",
  "up"   : __DIR__"topoftower",
]));
        set("outdoors", "guanwai");
        set("objects", ([
                __DIR__"npc/cityguard" : 2,
        ]) );
        setup();
}

