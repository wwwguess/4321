inherit ROOM;

void create()
{
        set("short", "ɽ·");
        set("long", @LONG
����һ�������߳�����Сɽ·����Ȼ����ȴ�ǹ�һ����ͨ�С�С·
˳��ɽ�н�Ϊƽ̹�ش�����������չ��
LONG
        );
        set("exits", ([ 
  "east" : __DIR__"mfoot",
  "west" : __DIR__"mroad2",
]));
        set("outdoors", "quicksand");
        set("objects", ([
                __DIR__"npc/trader" : 2,
        ]) );

        setup();
}
