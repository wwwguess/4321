// Mon  08-21-95

inherit NPC;

void create()
{
        seteuid(getuid());
        set_name("����",({"stone worker","worker"}));
        set("gender","����");
        set("age",47);
        set("str",30);
        set("con",20);
        set("combat_exp",100);
        set_temp("apply/dodge",10);
        add_money("coin",50);
        setup();
        carry_object("/obj/cloth")->wear();
        carry_object(__DIR__"obj/hammer")->wield();
}
