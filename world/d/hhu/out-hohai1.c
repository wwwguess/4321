// void.c (re-created after Elon screwed it up on 07-24-95)

inherit ROOM;

void create()
{
        set("short","���ش�ɭ��");
	set("long",@LONG	
����һƬ��ɭ�֣�͸��һ�����ص���Ϣ��
    �����������������Ĳ������(tree),���ϵ��޷��г����ǵ����֣�
����ɭ�����ر𾲣��������Լ��ĽŲ������о��Լ���������������ţ�
�����㲻��ë���Ȼ������
LONG
	);
        set("objects",([
        __DIR__"obj/red" :random(2),
        __DIR__"obj/green" :random(2)+1,
        ]));
        set("item_desc",([
            "tree":"����������Ұ�޵ĺ��У���æС�ĵ��Ĵ�������\n",
        ]));
        set("exits",([
        "south" : __DIR__"out-hohai",
        "north" : __DIR__"out-hohai",
        "west":"/d/road/jinling"
        ]));
	setup();
}

