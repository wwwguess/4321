inherit ROOM;

void create()
{
        set("short", "С��");
        set("long", @LONG
�����ѵ�С��ͨ�����Ϸ�, ����Ķ�����һ���ͱ�, �������
�ϱ���һƬŨ�ܵ����֡�
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
          "west" :__DIR__"sroad2",
          "southeast" :__DIR__"sroad5",
]));

        set("outdoors", "latemoon");
        setup();
        replace_program(ROOM);
}
