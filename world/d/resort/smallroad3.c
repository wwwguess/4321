inherit ROOM;

void create()
{
        set("short", "��С��");
        set("long", @LONG
һ������ǡ�˲���ɽ�п�����Է�̤����С�����������������
ɽ����չ�����Ե�é�ݸߴ���ߣ���ס����⡣ɽ���е�һ�ж��Ե���
ɭ�İ���
LONG
        );
        set("exits", ([ 
  "south" : __DIR__"smallroad2",
  "north" : __DIR__"smallroad4",
]));
        set("outdoors", "resort");

        setup();
        replace_program(ROOM);
}
