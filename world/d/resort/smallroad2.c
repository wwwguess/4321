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
  "south" : __DIR__"smallroad",
  "north" : __DIR__"smallroad3",
]));
        set("outdoors", "resort");

        setup();
        replace_program(ROOM);
}
