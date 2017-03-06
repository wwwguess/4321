// room_guard.c
inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name("����", ({ "guard" }) );
        set("title", "������");
        set("gender", "����" );
        set("age", 25);
        set("long", "�㿴��һ���⺷�Ĵ��ͷ��\n");
        set("str", 29);
        set("int", 14);
	set("cor", 56);
	set("max_kee",800);
        set("combat_exp", 10000);
        set("attitude", "heroism");
        set_skill("unarmed", 200);
        set_skill("parry", 140);
        set_skill("dodge", 220);

        set("inquiry", ([
                "����" : "�⵶���Ǹ�����, 
��˵�ǵ����ż�����������ʱ���ϴ͵ġ�",
                "�����" : "��ѩͤ����˭��֪���Ҽ���ү�����ˣ�",
        ]) );
        setup();
        add_money("silver", 12);
        add_money("coin", 500);
        carry_object("/obj/cloth")->wear();
}

