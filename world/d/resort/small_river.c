inherit ROOM;

void create()
{
        set("short", "С����ˮ");
        set("long", @LONG
һ���峺��СϪ�Ϻ����һ��ľ�š��ŵ��Ǳ���һƬïʢ�����֡�
��������÷������ӳ֮�У�һ�����ɵ�ׯԺ�������֡�
LONG
        );
        set("exits", ([ 
  "north" : __DIR__"gate",
  "east" : __DIR__"another_sky",
]));
        set("outdoors", "resort");

        setup();
        replace_program(ROOM);
}
