// /d/city/shangshu/feiwu

inherit ROOM;

void create()
{
        set("short", "����");
        set("long",@LONG
����һ���ѱ�������С�ݡ�С�ݺ�������Ҳ�ܳ�ʪ������΢���Ĺ���
����Լ����С������ҵضѷ���һЩ���С���ﵽ������֩��������Ȼ
�ܾ�û���������ˡ�
LONG
        );

        set("exits", ([
		"east":		__DIR__"road4",
                ]));

        setup();
        replace_program(ROOM);
}

