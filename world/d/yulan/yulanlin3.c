inherit ROOM;

void create()
{
        set("short", "��������");
        set("long", @LONG
����һƬï�ܵ��������֡�����������ݷ���ʧ�˷���
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
      "north" :__DIR__"yulanlin1",
      "east" :__DIR__"yulanlin",
      "west" :__DIR__"yulanlin2",
        "south" :__DIR__"yulanlin4",

]));
        set("outdoors", "yulan");
        setup();
        replace_program(ROOM);
}
