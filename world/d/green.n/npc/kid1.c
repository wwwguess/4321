// Mon  08-21-95

inherit NPC;
void create()
{
	seteuid(getuid());
        set_name("������С��",({"kid","child"}));
        set("gender","����");
        set("age",7);
        set("str",25);
        set("con",20);
        set("combat_exp",10);
        set_temp("apply/dodge",5);
        add_money("coin",5);
        setup();
        carry_object("/obj/cloth")->wear();
}
