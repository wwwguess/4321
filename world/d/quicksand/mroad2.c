inherit ROOM;

void create()
{
        set("short", "ɽ·");
        set("long", @LONG
����һ�������߳�����Сɽ·����Ȼ����ȴ�ǹ�һ����ͨ�С�С·
˳��ɽ�н�Ϊƽ̹�ش�����������չ��������һ�����ʵľ��¡�
LONG
        );
        set("exits", ([ 
  "east" : __DIR__"mroad",
  "west" : "/u/guanwai/grassland0",
  "south" : __DIR__"cliff",
]));
        set("outdoors", "quicksand");

        setup();
        replace_program(ROOM);
}
