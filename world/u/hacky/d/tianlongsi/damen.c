inherit ROOM;

void create()
{
        set("short", "����");
        set("long",@LONG
�������������´���ǰ��ֻ�����ƻֺ�������������Ͽ���һ������
( duilian )�����Ḳ�֣����е㲦����֮�⡣̧ͷ�����������һ���
ľ���ң����⡰��ʥ�¡��������֣�������ɡ�������ʽ�������������
�Խй��ˣ�����֮Ϊ�������¡���
LONG
        );
        set("outdoors", "tianlongsi");
        set("exits", ([
                "south" : __DIR__"talin",
                "north" : __DIR__"dadao4",
        ]));
	 set("item_desc",([
	  "duilian" : "\n    ������Ⱦ����Բ�ɡ�������Ե�������\n\n",
			  ]));	
//        set("objects",([
//                "wudang/npc/zhikeseng" : 1,
//        ]));
        setup();
        replace_program(ROOM);
}
