// 7-19-96 /d/village/npc/woman1.c

inherit NPC;

void wield_weapon();
void converse_one();

void create()
{
//	seteuid(geteuid());
        set_name("ũ��",({"woman"}));
        set("gender","Ů��");
        set("age",30);
       
	set("chat_chance",20);
	set("chat_msg", ({
		"ũ�������ҿ����Ķ������㵽����ȥ�ˣ�\n",
		"ũ���������м����ҵĶ��𣿣���ͷ����������Сץ����ֻ�����ꡣ\n",
	"ũ��̾����������\n",
	}) ); 
	set("inquiry",([
		"��":"�ҵĶ�ǰ���첻���ˣ��Һ����������Ҷ��Ҳ�������˵����ɽ��ץС���ӡ�\n",
	]) );
	
	set("combat_exp",(20+random(40)));
        set_temp("apply/dodge",(10+random(5)));
        add_money("coin",90);
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
        (: wield_weapon :),
        (: converse_one :) }) );
        
	setup();
        carry_object("/obj/cloth")->wear();
        //carry_object(__DIR__"obj/ricewine");
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
        command("say �������ǿ����Ķ�����������㻹С��!");
        command("slap "+(string)ob->query("id"));
    }
    else
        command("say �Դ���С����...");
    return;
}

