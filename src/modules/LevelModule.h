#pragma once

#include <functional>

#include <QMap>
#include <QTimer>

#include "core/Module.h"

#define LEVELMODULE_MAXIMUM_LEVEL          100
#define LEVELMODULE_EXP_REQUIREMENT        100 // per level
#define LEVELMODULE_EXP_GROWTH             1.12

class LevelModule : public Module
{
public:
	LevelModule();

	void OnSave(QJsonDocument& doc) const override;
	void OnLoad(const QJsonDocument& doc) override;

	void OnMessage(Discord::Client& client, const Discord::Message& message) override;

	void StatusCommand(QString& result, snowflake_t guild, snowflake_t user) override;

private:
	struct GuildLevelData {
		snowflake_t    user;
		int            exp;
		int            messageCount;
	};

	GuildLevelData GetData(snowflake_t guild, snowflake_t user);

	mutable QMap<snowflake_t, QList<GuildLevelData>> m_exp;
	QTimer m_timer;
};
