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
  "south":"/d/road/rfttocy2",
  "north" : __DIR__"smallroad2",
]));
        set("outdoors", "resort");

        setup();
        replace_program(ROOM);
}
