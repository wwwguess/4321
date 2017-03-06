// Mon  08-21-95

inherit NPC;

void wield_weapon();
void converse_one();

void create()
{
        seteuid(getuid());
        set_name("����",({"woman"}));
        set("gender","Ů��");
        set("age",(random(30)+12));
        set("combat_exp",(20+random(40)));
        set_temp("apply/dodge",(10+random(5)));
        add_money("coin",90);
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
        (: wield_weapon :),
        (: converse_one :) }) );
        setup();
        carry_object("/obj/cloth")->wear();
        carry_object(__DIR__"obj/ricewine");
        carry_object(__DIR__"obj/knife");
}

void wield_weapon()
{
    if (!query_temp("weapon")) {
        command("say û��ʶ���ҵĲ˵���\�ǰ�, ����!");
        command("wield knife");
        set("chat_chance_combat", 10);
    }
        return;
}

void converse_one()
{
    object ob;
    ob = this_player();
    if ((int)ob->query("age") < (int)query("age")) {
        command("say ��С��, ר���۸����˼�!");
        command("slap "+(string)ob->query("id"));
    }
    else
        command("say �Դ���С����...");
    return;
}

