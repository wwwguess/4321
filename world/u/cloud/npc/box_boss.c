// box_boss.c

inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name("����ү", ({ "boxboss", "lin" }) );
        set("title", "�ײ����ϰ�");
        set("gender", "����" );
        set("age", 55);
        set("long", "��λ��Ŀ���Ƶ����˾�Ӫ�ײ����Ѿ��кܶ����ˡ�\n");
        set("str", 29);
        set("int", 14);
	set("max_kee",800);

        set("combat_exp", 2000);
        set("attitude", "heroism");
        set_skill("unarmed", 60);
        set_skill("parry", 60);
        set_skill("dodge", 70);
	set_temp("apply/armor",20);

        set("inquiry", ([
                "�ײ�" : "����ô�����Ҫ�ײģ����˵�ɣ�",
                "������" : "��Ҳ֪��'�̺�����'����¥���ڽֶ��棬�ҳ�ȥ�ġ�", 
        ]) );

        setup();
        add_money("silver", 4);
        add_money("coin", 100);
        carry_object("/obj/cloth")->wear();
}

