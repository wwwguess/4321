
inherit ROOM;

void create()
{
        set("short", "��Ժ");
        set("long", @LONG
׳������Ժ������ȴʮ����ɭ�İ�����ǧֻ�������ţ����ȼ�ϵ���ͭ
���ڷ������������صĻ��档���ʵ���ǽ�������������裬��������Ŀ����
�ľ�����ɫ��������������У����Եù��ؿɲ���
LONG
        );
        set("exits", ([ 
  "north" : __DIR__"tower",
]));
        set("outdoors", "guanwai");
        setup();
        replace_program(ROOM);

}

